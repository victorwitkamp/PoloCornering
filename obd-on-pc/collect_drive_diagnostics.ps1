param(
    [string]$Port = "COM10",
    [int]$Minutes = 60,
    [int]$TimeoutSeconds = 3,
    [string]$RunPrefix = ""
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Continue"

$ScriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
Set-Location $ScriptDir

$LogDir = Join-Path $ScriptDir "logs"
New-Item -ItemType Directory -Force -Path $LogDir | Out-Null

$Started = Get-Date
if (-not $RunPrefix) {
    $RunPrefix = "drive_" + $Started.ToString("yyyyMMdd_HHmmss")
}

$CollectorLog = Join-Path $LogDir ($RunPrefix + "_collector_stdout.log")
$PidFile = Join-Path $LogDir ($RunPrefix + "_collector.pid")
$StopAt = $Started.AddMinutes($Minutes)

[System.Diagnostics.Process]::GetCurrentProcess().Id | Set-Content -Path $PidFile -Encoding ASCII

function Write-CollectorLine {
    param([string]$Line)
    $Stamped = "[" + (Get-Date).ToString("o") + "] " + $Line
    $Stamped | Tee-Object -FilePath $CollectorLog -Append
}

function Invoke-Probe {
    param(
        [string]$Mode,
        [string]$Commands,
        [string]$ReadProfile,
        [string]$RunId
    )

    $ProbeArgs = @(
        ".\vw_tp20_readonly_probe.py",
        "--mode", $Mode,
        "--port", $Port,
        "--baud", "38400",
        "--timeout", [string]$TimeoutSeconds,
        "--parameter-profile", "carista_then_minimal",
        "--run-id", $RunId
    )
    if ($ReadProfile) {
        $ProbeArgs += @("--read-profile", $ReadProfile)
    }
    elseif ($Commands) {
        $ProbeArgs += @("--read-commands", $Commands)
    }

    Write-CollectorLine "START mode=$Mode profile=$ReadProfile commands=$Commands run_id=$RunId"
    & python @ProbeArgs 2>&1 | Tee-Object -FilePath $CollectorLog -Append
    Write-CollectorLine "END mode=$Mode run_id=$RunId exit=$LASTEXITCODE"
}

Write-CollectorLine "Drive diagnostic collector started port=$Port minutes=$Minutes timeout=$TimeoutSeconds"
Write-CollectorLine "Read-only only. Underlying probe blocks 27, 2E, 31, and 3B."

$Round = 1
$CoreCommands = "220601,22F187,22F189,22F197,22F1A3,22F1AA,1802FF00,1902FF"
$PeriodicCommands = "1A9B,1A9F,1A91,1A9A,1A86,220606,22F17E,22F18C,22F191,22F1DF"

while ((Get-Date) -lt $StopAt) {
    $RoundStamp = (Get-Date).ToString("HHmmss")
    $RoundId = "{0}_r{1:D3}_{2}" -f $RunPrefix, $Round, $RoundStamp

    Invoke-Probe -Mode "direct_sequence" -ReadProfile "carista_read_values" -RunId ($RoundId + "_read_values")
    Invoke-Probe -Mode "direct_read" -Commands $CoreCommands -RunId ($RoundId + "_core")

    if (($Round % 5) -eq 0) {
        Invoke-Probe -Mode "direct_read" -Commands $PeriodicCommands -RunId ($RoundId + "_periodic")
    }

    $Round += 1
}

Write-CollectorLine "Drive diagnostic collector finished"
