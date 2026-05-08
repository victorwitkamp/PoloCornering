<#
run_restore_expert_backup_session.ps1 - PowerShell wrapper for restoring the expert BCM coding backup.
Remove after session.

Usage:
    .\run_restore_expert_backup_session.ps1          # read-only
    .\run_restore_expert_backup_session.ps1 -Write   # read + gated restore write
    .\run_restore_expert_backup_session.ps1 -DisableTurnSignalFogs -Write
    .\run_restore_expert_backup_session.ps1 -ClearByte12Bit0 -Write
    .\run_restore_expert_backup_session.ps1 -SetByte21Bit2 -Write
    .\run_restore_expert_backup_session.ps1 -ClearDrlViaFogs -Write
    .\run_restore_expert_backup_session.ps1 -ClearDrlViaFogs -ClearByte21Bit7 -SetByte21Bit2 -Write
#>
param(
    [string]$Port = "COM10",
    [int]$Baud = 38400,
    [switch]$DisableTurnSignalFogs,
    [switch]$SetByte12Bit0,
    [switch]$ClearByte12Bit0,
    [switch]$SetByte12Bit6,
    [switch]$ClearByte12Bit6,
    [switch]$SetByte21Bit2,
    [switch]$ClearByte21Bit2,
    [switch]$SetByte21Bit5,
    [switch]$ClearByte21Bit5,
    [switch]$SetByte21Bit7,
    [switch]$ClearByte21Bit7,
    [switch]$SetByte23Bit2,
    [switch]$ClearByte23Bit2,
    [switch]$SetDrlViaFogs,
    [switch]$ClearDrlViaFogs,
    [switch]$Write
)

$Script = Join-Path $PSScriptRoot "run_bcm_coding_session.py"
$RepoRoot = Split-Path -Parent $PSScriptRoot
$VenvPython = Join-Path $RepoRoot ".venv\Scripts\python.exe"
$Python = if (Test-Path $VenvPython) { $VenvPython } else { "python" }
$PythonArgs = @($Script, "--port", $Port, "--baud", $Baud)
$BitArgs = @()
if ($SetByte12Bit0) { $BitArgs += @("--set-bit", "byte12-bit0") }
if ($ClearByte12Bit0) { $BitArgs += @("--clear-bit", "byte12-bit0") }
if ($SetByte12Bit6) { $BitArgs += @("--set-bit", "byte12-bit6") }
if ($ClearByte12Bit6) { $BitArgs += @("--clear-bit", "byte12-bit6") }
if ($SetByte21Bit2) { $BitArgs += @("--set-bit", "byte21-bit2") }
if ($ClearByte21Bit2) { $BitArgs += @("--clear-bit", "byte21-bit2") }
if ($SetByte21Bit5) { $BitArgs += @("--set-bit", "byte21-bit5") }
if ($ClearByte21Bit5) { $BitArgs += @("--clear-bit", "byte21-bit5") }
if ($SetByte21Bit7) { $BitArgs += @("--set-bit", "byte21-bit7") }
if ($ClearByte21Bit7) { $BitArgs += @("--clear-bit", "byte21-bit7") }
if ($SetByte23Bit2) { $BitArgs += @("--set-bit", "byte23-bit2") }
if ($ClearByte23Bit2) { $BitArgs += @("--clear-bit", "byte23-bit2") }
if ($SetDrlViaFogs) { $BitArgs += @("--set-bit", "drl-via-fogs") }
if ($ClearDrlViaFogs) { $BitArgs += @("--clear-bit", "drl-via-fogs") }
if ($DisableTurnSignalFogs -and $BitArgs.Count -gt 0) {
    throw "Do not combine -DisableTurnSignalFogs with current-coding bit set/clear switches."
}
if ($DisableTurnSignalFogs) {
    $PythonArgs += @("--operation", "restore-expert-backup-no-turn-signal-fogs")
} elseif ($BitArgs.Count -gt 0) {
    $PythonArgs += $BitArgs
}
if ($Write) {
    $PythonArgs += "--write"
}
Write-Host ("Running: $Python " + ($PythonArgs -join " "))
& $Python @PythonArgs
