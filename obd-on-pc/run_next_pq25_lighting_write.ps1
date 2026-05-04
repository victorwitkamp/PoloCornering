param(
    [string]$Port = "COM10",
    [int]$Baud = 38400,
    [string]$PythonExe = "",
    [double]$Timeout = 2.5,
    [ValidateSet("minimal", "carista", "carista_exact", "carista_then_minimal")]
    [string]$ParameterProfile = "carista_then_minimal",
    [ValidateSet("diagnostics-off-cornering", "previous-cornering-reference", "restored-baseline", "expert-historical-backup")]
    [string]$ExpectedProfile = "diagnostics-off-cornering",
    [ValidateSet("diagnostics-off-cornering", "previous-cornering-reference", "restored-baseline", "expert-historical-backup")]
    [string]$TargetProfile = "previous-cornering-reference",
    [int]$ChannelOpenAttempts = 2,
    [int]$ChannelReopenDelayMs = 1000,
    [switch]$AllowDefaultChannelParameters,
    [switch]$Execute
)

$ErrorActionPreference = "Stop"
$ScriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$WorkspaceRoot = Split-Path -Parent $ScriptDir
Set-Location $ScriptDir

if (-not $PythonExe) {
    $VenvPython = Join-Path $WorkspaceRoot ".venv\Scripts\python.exe"
    if (Test-Path $VenvPython) {
        $PythonExe = $VenvPython
    } else {
        $PythonExe = "python"
    }
}

$ArgsList = @(
    ".\write_pq25_lighting_profile.py",
    "--port", $Port,
    "--baud", "$Baud",
    "--timeout", "$Timeout",
    "--parameter-profile", $ParameterProfile,
    "--channel-open-attempts", "$ChannelOpenAttempts",
    "--channel-reopen-delay-ms", "$ChannelReopenDelayMs",
    "--expected-profile", $ExpectedProfile,
    "--target-profile", $TargetProfile
)

if ($AllowDefaultChannelParameters) {
    $ArgsList += "--allow-default-channel-parameters"
}

if ($Execute) {
    $ArgsList += @("--execute", "--i-understand-this-writes-bcm-coding")
}

Write-Host "PQ25 lighting write runner"
Write-Host "Expected profile: $ExpectedProfile"
Write-Host "Target profile:   $TargetProfile"
Write-Host "Port:             $Port"
Write-Host "Parameter profile:$ParameterProfile"
Write-Host "Channel attempts: $ChannelOpenAttempts"
Write-Host "Reopen delay:     $ChannelReopenDelayMs ms"
Write-Host "Allow defaults:   $AllowDefaultChannelParameters"
Write-Host "Python:           $PythonExe"
Write-Host "Execute:          $Execute"
Write-Host ""

& $PythonExe @ArgsList
