param(
    [string]$Port = "COM10",
    [int]$Baud = 38400,
    [switch]$DryRun,
    [switch]$IncludeKwpReads,
    [switch]$IncludeOldSessionBranch
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

$Root = Split-Path -Parent $MyInvocation.MyCommand.Path
Set-Location $Root

$Commands = @()
$Commands += ,@(
    "python", ".\vw_tp20_readonly_probe.py",
    "--mode", "direct_read",
    "--port", $Port,
    "--baud", "$Baud",
    "--parameter-profile", "minimal",
    "--read-commands", "220600",
    "--read-counter", "0",
    "--run-id", "pq25_next_baseline_220600"
)
$Commands += ,@(
    "python", ".\decode_pq25_longcoding.py",
    "--coding-file", ".\logs\pq25_next_baseline_220600_direct_read_summary.json",
    "--output", ".\logs\pq25_next_baseline_220600_settings_report.txt"
)

if ($IncludeKwpReads) {
    $Commands += ,@(
        "python", ".\vw_tp20_readonly_probe.py",
        "--mode", "direct_read",
        "--port", $Port,
        "--baud", "$Baud",
        "--parameter-profile", "minimal",
        "--read-commands", "1A9A,1A9B",
        "--read-counter", "0",
        "--run-id", "pq25_next_direct_kwp"
    )
}

if ($IncludeOldSessionBranch) {
    $Commands += ,@(
        "python", ".\vw_tp20_readonly_probe.py",
        "--mode", "session_sweep",
        "--port", $Port,
        "--baud", "$Baud",
        "--parameter-profile", "minimal",
        "--sessions", "1089",
        "--run-id", "pq25_next_session_1089"
    )
    $Commands += ,@(
        "python", ".\vw_tp20_readonly_probe.py",
        "--mode", "read_sweep",
        "--port", $Port,
        "--baud", "$Baud",
        "--parameter-profile", "minimal",
        "--session", "1089",
        "--ack", "none",
        "--delay-ms", "100",
        "--read-commands", "1A9B",
        "--run-id", "pq25_next_session_1A9B"
    )
}

foreach ($Command in $Commands) {
    $Display = $Command -join " "
    if ($DryRun) {
        Write-Host $Display
        continue
    }

    Write-Host ""
    Write-Host $Display
    $Executable = $Command[0]
    $Arguments = $Command[1..($Command.Count - 1)]
    & $Executable @Arguments
    if ($LASTEXITCODE -ne 0) {
        throw "Command failed with exit code $LASTEXITCODE"
    }
}

Write-Host ""
Write-Host "Logs are in: $Root\logs"
