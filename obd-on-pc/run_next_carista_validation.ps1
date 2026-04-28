param(
    [string]$Port = "COM10",
    [int]$Baud = 38400,
    [switch]$DryRun,
    [switch]$IncludeKwpComparison,
    [switch]$IncludeSessionComparison
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

$Root = Split-Path -Parent $MyInvocation.MyCommand.Path
$WorkspaceRoot = Split-Path -Parent $Root
$VenvPython = Join-Path $WorkspaceRoot ".venv\Scripts\python.exe"
$Python = if (Test-Path $VenvPython) { $VenvPython } else { "python" }
$DocsLogDir = Join-Path $WorkspaceRoot "docs\obd-on-pc\logs"
Set-Location $Root

$SummaryFiles = New-Object System.Collections.Generic.List[string]

function Invoke-Step {
    param([string[]]$Command, [string]$OutFile = "")

    $Display = $Command -join " "
    Write-Host ""
    Write-Host $Display
    if ($DryRun) {
        return
    }

    $Executable = $Command[0]
    $Arguments = $Command[1..($Command.Count - 1)]
    if ($OutFile) {
        & $Executable @Arguments | Tee-Object -FilePath $OutFile
    } else {
        & $Executable @Arguments
    }
    if ($LASTEXITCODE -ne 0) {
        throw "Command failed with exit code $LASTEXITCODE"
    }
}

function Add-SummaryFile {
    param([string]$Path)
    if ($DryRun -or (Test-Path $Path)) {
        $SummaryFiles.Add($Path) | Out-Null
    } else {
        Write-Warning "Expected summary was not written: $Path"
    }
}

$BaselineRunId = "pq25_carista_validation_baseline_220600"
$BaselineSummary = ".\logs\${BaselineRunId}_direct_read_summary.json"
$BaselineReport = Join-Path $DocsLogDir "${BaselineRunId}_settings_report.txt"
$UdsPlan = Join-Path $DocsLogDir "${BaselineRunId}_uds_write_dry_run.txt"

Write-Host "Read-only Carista UDS validation"
Write-Host "Primary proof path: 220600 coding + 22F1A5 workshop-code payload"
Write-Host "Prepared write shape: 2EF199 date, 2EF198 workshop code, then 2E0600 target coding"
Write-Host "No 27/2E/31/3B write or routine-control services are sent."

Invoke-Step -Command @(
    $Python, ".\vw_tp20_readonly_probe.py",
    "--mode", "direct_read",
    "--port", $Port,
    "--baud", "$Baud",
    "--parameter-profile", "minimal",
    "--read-commands", "220600,22F1A5",
    "--read-counter", "0",
    "--run-id", $BaselineRunId
)
Add-SummaryFile -Path $BaselineSummary

Invoke-Step -Command @(
    $Python, ".\decode_pq25_longcoding.py",
    "--coding-file", $BaselineSummary,
    "--output", $BaselineReport
)

Invoke-Step -Command @(
    $Python, ".\write_carista_uds_coding.py",
    "--coding-file", $BaselineSummary,
    "--workshop-code-file", $BaselineSummary
) -OutFile $UdsPlan

if ($IncludeKwpComparison) {
    $MinimalRunId = "pq25_carista_validation_carista_builders_minimal"
    $MinimalSummary = ".\logs\${MinimalRunId}_direct_read_summary.json"

    $SequenceRunId = "pq25_carista_validation_same_channel_minimal"
    $SequenceSummary = ".\logs\${SequenceRunId}_direct_sequence_summary.json"

    $CaristaParamRunId = "pq25_carista_validation_carista_builders_carista_params"
    $CaristaParamSummary = ".\logs\${CaristaParamRunId}_direct_read_summary.json"

    Invoke-Step -Command @(
        $Python, ".\vw_tp20_readonly_probe.py",
        "--mode", "direct_read",
        "--port", $Port,
        "--baud", "$Baud",
        "--parameter-profile", "minimal",
        "--read-commands", "1A9B,1A9A",
        "--read-counter", "0",
        "--run-id", $MinimalRunId
    )
    Add-SummaryFile -Path $MinimalSummary

    Invoke-Step -Command @(
        $Python, ".\vw_tp20_readonly_probe.py",
        "--mode", "direct_sequence",
        "--port", $Port,
        "--baud", "$Baud",
        "--parameter-profile", "minimal",
        "--read-commands", "220600,1A9B,1A9A",
        "--read-counter", "0",
        "--run-id", $SequenceRunId
    )
    Add-SummaryFile -Path $SequenceSummary

    Invoke-Step -Command @(
        $Python, ".\vw_tp20_readonly_probe.py",
        "--mode", "direct_read",
        "--port", $Port,
        "--baud", "$Baud",
        "--parameter-profile", "carista",
        "--read-commands", "1A9B,1A9A",
        "--read-counter", "0",
        "--run-id", $CaristaParamRunId
    )
    Add-SummaryFile -Path $CaristaParamSummary
}

if ($IncludeSessionComparison) {
    $SessionRunId = "pq25_carista_validation_session_1089_1A9B"
    $SessionSummary = ".\logs\${SessionRunId}_read_sweep_summary.json"
    Invoke-Step -Command @(
        $Python, ".\vw_tp20_readonly_probe.py",
        "--mode", "read_sweep",
        "--port", $Port,
        "--baud", "$Baud",
        "--parameter-profile", "minimal",
        "--session", "1089",
        "--ack", "none",
        "--delay-ms", "100",
        "--read-commands", "1A9B",
        "--run-id", $SessionRunId
    )
    Add-SummaryFile -Path $SessionSummary
}

$Report = Join-Path $DocsLogDir "pq25_carista_validation_report.md"
$WorkflowReport = Join-Path $DocsLogDir "pq25_carista_repro_workflow.json"
$JsonReport = ".\logs\pq25_carista_validation_report.json"
if (-not $DryRun) {
    New-Item -ItemType Directory -Force -Path $DocsLogDir | Out-Null
}
$SummaryArgs = @($Python, ".\summarize_carista_tuple_proof_read.py", "--summaries") + $SummaryFiles.ToArray() + @("--output", $Report, "--json-output", $JsonReport)
Invoke-Step -Command $SummaryArgs

$WorkflowArgs = @($Python, ".\carista_vagcan_repro.py", "--validate-workflow", "--coding-file", $BaselineSummary)
foreach ($SummaryFile in $SummaryFiles) {
    $WorkflowArgs += @("--ecu-info-file", $SummaryFile)
}
$WorkflowArgs += @("--json-output", $WorkflowReport)
Invoke-Step -Command $WorkflowArgs

Write-Host ""
Write-Host "Prepared files:"
Write-Host "  $BaselineSummary"
Write-Host "  $BaselineReport"
Write-Host "  $UdsPlan"
if ($IncludeKwpComparison) {
    Write-Host "  $MinimalSummary"
    Write-Host "  $SequenceSummary"
    Write-Host "  $CaristaParamSummary"
}
Write-Host "  $Report"
Write-Host "  $WorkflowReport"
Write-Host "  $JsonReport"
Write-Host ""
Write-Host "If 220600 and 22F1A5 are positive, the dry-run UDS plan is the next write candidate."
Write-Host "Do not execute it without checking the generated target and using write_carista_uds_coding.py guards."
