param(
    [string]$Port = "COM10",
    [string]$States = "",
    [string]$ReadProfile = "bcm_light_debug",
    [string]$ReadCommands = "",
    [ValidateSet("minimal", "legacy", "carista", "carista_exact", "carista_then_minimal", "all")]
    [string]$ParameterProfile = "carista_then_minimal",
    [int]$RawCanSeconds = 0,
    [string]$RawCanFilter = "",
    [string]$RawCanMonitorMode = "",
    [int]$RawCanPerHeaderMs = 0,
    [string]$RawHeaders = "",
    [int]$Repeats = 1,
    [int]$SettleMs = 500,
    [int]$InterCommandMs = 100,
    [string]$RunId = "",
    [switch]$SkipChannelParameters,
    [switch]$PreflightOnly,
    [switch]$NoPrompts
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

$ScriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$WorkspaceRoot = Split-Path -Parent $ScriptDir
$Python = Join-Path $WorkspaceRoot ".venv\Scripts\python.exe"
if (-not (Test-Path $Python)) {
    $Python = "python"
}

Set-Location $ScriptDir

$ArgsList = @(
    ".\capture_bcm_light_state.py",
    "--port", $Port,
    "--baud", "38400",
    "--timeout", "2.5",
    "--parameter-profile", $ParameterProfile,
    "--read-profile", $ReadProfile,
    "--repeats", [string]$Repeats
)

if ($States) {
    $ArgsList += @("--states", $States)
}

if ($ReadCommands) {
    $ArgsList += @("--read-commands", $ReadCommands)
}

if ($RawCanSeconds -gt 0) {
    $ArgsList += @("--raw-can-ms", [string]($RawCanSeconds * 1000))
}

if ($RawCanFilter) {
    $ArgsList += @("--raw-can-filter", $RawCanFilter)
}

if ($RawCanMonitorMode) {
    $ArgsList += @("--raw-can-monitor-mode", $RawCanMonitorMode)
}

if ($RawCanPerHeaderMs -gt 0) {
    $ArgsList += @("--raw-can-per-header-ms", [string]$RawCanPerHeaderMs)
}

if ($RawHeaders) {
    $ArgsList += @("--raw-headers", $RawHeaders)
}

if ($SettleMs -ne 500) {
    $ArgsList += @("--settle-ms", [string]$SettleMs)
}

if ($InterCommandMs -ne 100) {
    $ArgsList += @("--inter-command-ms", [string]$InterCommandMs)
}

if ($RunId) {
    $ArgsList += @("--run-id", $RunId)
}

if ($SkipChannelParameters) {
    $ArgsList += "--skip-channel-parameters"
}

if ($PreflightOnly) {
    $ArgsList += "--preflight-only"
}

if ($NoPrompts) {
    $ArgsList += "--no-prompts"
}

& $Python @ArgsList
exit $LASTEXITCODE