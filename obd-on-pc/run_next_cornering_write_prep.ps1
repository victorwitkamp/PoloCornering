param(
    [string]$Port = "COM10",
    [int]$Baud = 38400,
    [switch]$DryRun
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

$Root = Split-Path -Parent $MyInvocation.MyCommand.Path
$WorkspaceRoot = Split-Path -Parent $Root
$VenvPython = Join-Path $WorkspaceRoot ".venv\Scripts\python.exe"
$Python = if (Test-Path $VenvPython) { $VenvPython } else { "python" }
$DocsLogDir = Join-Path $WorkspaceRoot "docs\obd-on-pc\logs"
Set-Location $Root

$RunId = "pq25_next_carista_uds_prep"
$Summary = ".\logs\${RunId}_direct_read_summary.json"
$Report = Join-Path $DocsLogDir "${RunId}_settings_report.txt"
$Plan = Join-Path $DocsLogDir "${RunId}_uds_write_dry_run.txt"

if (-not $DryRun) {
    New-Item -ItemType Directory -Force -Path $DocsLogDir | Out-Null
}

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

Write-Host "Read-only prep for guarded Carista UDS DID 0600 write"
Write-Host "Reads 220600 and 22F1A5, then prints the dry-run F199/F198/0600 plan."

Invoke-Step -Command @(
    $Python, ".\vw_tp20_readonly_probe.py",
    "--mode", "direct_read",
    "--port", $Port,
    "--baud", "$Baud",
    "--parameter-profile", "minimal",
    "--read-commands", "220600,22F1A5",
    "--read-counter", "0",
    "--run-id", $RunId
)

Invoke-Step -Command @(
    $Python, ".\decode_pq25_longcoding.py",
    "--coding-file", $Summary,
    "--output", $Report
)

Invoke-Step -Command @(
    $Python, ".\write_carista_uds_coding.py",
    "--coding-file", $Summary,
    "--workshop-code-file", $Summary
) -OutFile $Plan

Write-Host ""
Write-Host "Prepared files:"
Write-Host "  $Summary"
Write-Host "  $Report"
Write-Host "  $Plan"
Write-Host ""
Write-Host "This wrapper does not execute writes. Review the target and use write_carista_uds_coding.py guards for execution."
