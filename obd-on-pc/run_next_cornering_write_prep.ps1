param(
    [string]$Port = "COM10",
    [int]$Baud = 38400,
    [switch]$DryRun,
    [string]$BaseFogRawAddress4 = "",
    [Nullable[int]]$BaseFogCodingType = $null,
    [string]$BaseFogTail = "",
    [string]$TurnSignalRawAddress4 = "",
    [Nullable[int]]$TurnSignalCodingType = $null,
    [string]$TurnSignalTail = ""
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

$Root = Split-Path -Parent $MyInvocation.MyCommand.Path
Set-Location $Root

$Summary = ".\logs\pq25_next_baseline_220600_direct_read_summary.json"
$Report = ".\logs\pq25_next_baseline_220600_settings_report.txt"
$BaseFogPlan = ".\logs\pq25_next_base_fog_tuple_dry_run.txt"
$TurnSignalPlan = ".\logs\pq25_next_turn_signal_tuple_dry_run.txt"

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

function New-TupleDryRunCommand {
    param(
        [string]$Fix,
        [string]$RawAddress4,
        [Nullable[int]]$CodingType,
        [string]$Tail
    )

    if ($RawAddress4 -or $null -ne $CodingType) {
        if (-not $RawAddress4 -or $null -eq $CodingType) {
            throw "${Fix}: rawAddress4 and codingType must be supplied together"
        }
        $Command = @(
            "python", ".\write_carista_3b9a_tuple.py",
            "--coding-file", $Summary,
            "--cornering-fix", $Fix,
            "--run-id", "pq25_next_${Fix}_tuple",
            "--raw-address4", $RawAddress4,
            "--coding-type", "$CodingType"
        )
        if ($Tail) {
            $Command += @("--tail", $Tail)
        }
        return $Command
    }

    return @(
        "python", ".\compose_carista_3b9a_tuple.py",
        "--coding-file", $Summary,
        "--cornering-fix", $Fix
    )
}

Invoke-Step -Command @(
    "python", ".\vw_tp20_readonly_probe.py",
    "--mode", "direct_read",
    "--port", $Port,
    "--baud", "$Baud",
    "--parameter-profile", "minimal",
    "--read-commands", "220600",
    "--read-counter", "0",
    "--run-id", "pq25_next_baseline_220600"
)

Invoke-Step -Command @(
    "python", ".\decode_pq25_longcoding.py",
    "--coding-file", $Summary,
    "--output", $Report
)

Invoke-Step -Command (New-TupleDryRunCommand -Fix "base-fog" -RawAddress4 $BaseFogRawAddress4 -CodingType $BaseFogCodingType -Tail $BaseFogTail) -OutFile $BaseFogPlan
Invoke-Step -Command (New-TupleDryRunCommand -Fix "turn-signal" -RawAddress4 $TurnSignalRawAddress4 -CodingType $TurnSignalCodingType -Tail $TurnSignalTail) -OutFile $TurnSignalPlan

Write-Host ""
Write-Host "Prepared files:"
Write-Host "  $Summary"
Write-Host "  $Report"
Write-Host "  $BaseFogPlan"
Write-Host "  $TurnSignalPlan"
Write-Host ""
Write-Host "This wrapper does not execute writes. If a real Carista trace provides rawAddress4/codingType/tail,"
Write-Host "review the dry-run request and run write_carista_3b9a_tuple.py manually with --execute and --confirm-request."
