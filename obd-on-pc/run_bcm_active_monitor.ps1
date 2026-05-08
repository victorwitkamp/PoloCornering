<#
run_bcm_active_monitor.ps1 - PowerShell wrapper for read-only BCM active polling.

Usage:
    .\run_bcm_active_monitor.ps1
    .\run_bcm_active_monitor.ps1 -Profile all-safe -Cycles 1
    .\run_bcm_active_monitor.ps1 -Commands 1A9B,1A9F,1A9A -SetupCommand 1089 -Cycles 1
    .\run_bcm_active_monitor.ps1 -Kwp21Range 10,1F -Cycles 1
    .\run_bcm_active_monitor.ps1 -Did22Range 0550,056F -Cycles 1
    .\run_bcm_active_monitor.ps1 -Service1ARange 80,9F -Cycles 1
    .\run_bcm_active_monitor.ps1 -Profile scaling-known-dids -Cycles 1
    .\run_bcm_active_monitor.ps1 -VagAdaptationKind short -VagAdaptationChannel 2F -Cycles 1
    .\run_bcm_active_monitor.ps1 -Cycles 10 -Label fog_switch_toggle
#>
param(
    [string]$Port = "COM10",
    [int]$Baud = 38400,
    [string[]]$Profile = @(),
    [string[]]$Commands = @(),
    [string[]]$Kwp21Range = @(),
    [string[]]$Did22Range = @(),
    [string[]]$Service1ARange = @(),
    [ValidateSet("short", "long")]
    [string]$VagAdaptationKind = "short",
    [string]$VagAdaptationChannel = "",
    [string[]]$SetupCommand = @(),
    [int]$Cycles = 6,
    [double]$Pause = 1.0,
    [string]$Label = "active_monitor",
    [switch]$ListProfiles
)

$Script = Join-Path $PSScriptRoot "run_bcm_active_monitor.py"
$RepoRoot = Split-Path -Parent $PSScriptRoot
$VenvPython = Join-Path $RepoRoot ".venv\Scripts\python.exe"
$Python = if (Test-Path $VenvPython) { $VenvPython } else { "python" }
$PythonArgs = @(
    $Script,
    "--port", $Port,
    "--baud", $Baud,
    "--cycles", $Cycles,
    "--pause", $Pause,
    "--label", $Label
)
if ($ListProfiles) {
    $PythonArgs += "--list-profiles"
}
foreach ($ProfileName in $Profile) {
    $PythonArgs += @("--profile", $ProfileName)
}
foreach ($Setup in $SetupCommand) {
    $PythonArgs += @("--setup-command", $Setup)
}
if ($Kwp21Range.Count -gt 0) {
    $PythonArgs += "--kwp21-range"
    $PythonArgs += $Kwp21Range
}
if ($Did22Range.Count -gt 0) {
    $PythonArgs += "--did22-range"
    $PythonArgs += $Did22Range
}
if ($Service1ARange.Count -gt 0) {
    $PythonArgs += "--service1a-range"
    $PythonArgs += $Service1ARange
}
if ($VagAdaptationChannel -ne "") {
    $PythonArgs += @("--vag-adaptation-kind", $VagAdaptationKind)
    $PythonArgs += @("--vag-adaptation-channel", $VagAdaptationChannel)
}
if ($Commands.Count -gt 0) {
    $PythonArgs += "--commands"
    $PythonArgs += $Commands
}

Write-Host ("Running: $Python " + ($PythonArgs -join " "))
& $Python @PythonArgs
