<#
pq25_write_session.ps1 - PowerShell wrapper for guarded PQ25 BCM coding writes.

Usage:
    .\obd-on-pc\pq25_write_session.ps1 -Operation restore-expert-backup
    .\obd-on-pc\pq25_write_session.ps1 -Operation restore-expert-backup -Write
    .\obd-on-pc\pq25_write_session.ps1 -SetBit byte21-bit2 -ClearBit byte21-bit7
    .\obd-on-pc\pq25_write_session.ps1 -ToCoding "<30-byte-hex>" -Write
#>
param(
    [string]$Port = "COM10",
    [int]$Baud = 38400,
    [ValidateSet(
        "restore-expert-backup",
        "restore-expert-backup-no-turn-signal-fogs",
        "clear-byte12-bit0",
        "drl-via-fogs"
    )]
    [string]$Operation = "",
    [string]$ToCoding = "",
    [ValidateSet(
        "byte12-bit0",
        "byte12-bit6",
        "byte21-bit2",
        "byte21-bit5",
        "byte21-bit7",
        "byte23-bit2",
        "drl-via-fogs"
    )]
    [string[]]$SetBit = @(),
    [ValidateSet(
        "byte12-bit0",
        "byte12-bit6",
        "byte21-bit2",
        "byte21-bit5",
        "byte21-bit7",
        "byte23-bit2",
        "drl-via-fogs"
    )]
    [string[]]$ClearBit = @(),
    [string]$LogDir = "",
    [switch]$Write
)

$Script = Join-Path $PSScriptRoot "pq25_write_session.py"
$RepoRoot = Split-Path -Parent $PSScriptRoot
$VenvPython = Join-Path $RepoRoot ".venv\Scripts\python.exe"
$Python = if (Test-Path $VenvPython) { $VenvPython } else { "python" }
$PythonArgs = @(
    $Script,
    "--port", $Port,
    "--baud", $Baud
)

if ($Operation -ne "") {
    $PythonArgs += @("--operation", $Operation)
}
if ($ToCoding -ne "") {
    $PythonArgs += @("--to-coding", $ToCoding)
}
foreach ($Bit in $SetBit) {
    $PythonArgs += @("--set-bit", $Bit)
}
foreach ($Bit in $ClearBit) {
    $PythonArgs += @("--clear-bit", $Bit)
}
if ($LogDir -ne "") {
    $PythonArgs += @("--log-dir", $LogDir)
}
if ($Write) {
    $PythonArgs += "--write"
}

Write-Host ("Running: $Python " + ($PythonArgs -join " "))
& $Python @PythonArgs
