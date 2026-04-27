param(
    [ValidateSet("check", "trace", "summarize")]
    [string]$Action = "check",
    [string]$Package = "com.prizmos.carista",
    [string]$TraceFile = ".\trace_logs\carista_cornering_trace.jsonl",
    [string]$SummaryFile = ".\trace_logs\carista_cornering_trace_summary.txt",
    [string]$DeviceId,
    [string]$FridaHost,
    [int]$TimeoutMs = 5000,
    [switch]$Spawn,
    [switch]$All
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

$ScriptRoot = Split-Path -Parent $MyInvocation.MyCommand.Path
$WorkspaceRoot = Split-Path -Parent $ScriptRoot
$Python = Join-Path $WorkspaceRoot ".venv\Scripts\python.exe"
$TraceScript = Join-Path $ScriptRoot "run_carista_cornering_trace.py"
$SummaryScript = Join-Path $ScriptRoot "summarize_carista_cornering_trace.py"

if (-not (Test-Path $Python)) {
    throw "Python environment not found at $Python"
}

function Resolve-TracePath([string]$PathText) {
    if ([System.IO.Path]::IsPathRooted($PathText)) {
        return $PathText
    }
    return Join-Path $ScriptRoot $PathText
}

function Find-Adb {
    $command = Get-Command adb -ErrorAction SilentlyContinue
    if ($command -and $command.Source) {
        return $command.Source
    }

    $candidates = @(
        $(if ($env:ANDROID_SDK_ROOT) { Join-Path $env:ANDROID_SDK_ROOT "platform-tools\adb.exe" }),
        $(if ($env:ANDROID_HOME) { Join-Path $env:ANDROID_HOME "platform-tools\adb.exe" }),
        "$env:LOCALAPPDATA\Android\Sdk\platform-tools\adb.exe",
        "$env:USERPROFILE\AppData\Local\Android\Sdk\platform-tools\adb.exe",
        "$env:LOCALAPPDATA\Microsoft\WinGet\Packages\Google.PlatformTools_Microsoft.Winget.Source_8wekyb3d8bbwe\platform-tools\adb.exe",
        "$env:ProgramFiles\Android\platform-tools\adb.exe",
        "$env:ProgramFiles(x86)\Android\android-sdk\platform-tools\adb.exe",
        "C:\platform-tools\adb.exe"
    )
    foreach ($candidate in $candidates) {
        if ($candidate -and (Test-Path $candidate)) {
            return $candidate
        }
    }
    return $null
}

function Invoke-AdbDevices([string]$AdbPath) {
    $output = & $AdbPath devices -l
    $lines = @($output)
    $lines | ForEach-Object { Write-Host $_ }

    $deviceLines = $lines | Where-Object {
        $_ -and
        $_ -notmatch '^List of devices attached' -and
        $_ -notmatch '^\*$'
    }

    if (-not $deviceLines) {
        Write-Warning "adb is installed but no Android device is attached. Unlock the phone, reconnect the USB cable, set USB mode to File Transfer, and accept any USB debugging prompt on the phone."
        return
    }

    $unauthorized = $deviceLines | Where-Object { $_ -match '\sunauthorized(\s|$)' }
    if ($unauthorized) {
        Write-Warning "An Android device is connected but unauthorized. Unlock the phone and accept the USB debugging RSA fingerprint prompt, or revoke USB debugging authorizations and reconnect if the prompt is not visible."
        return
    }

    $offline = $deviceLines | Where-Object { $_ -match '\soffline(\s|$)' }
    if ($offline) {
        Write-Warning "An Android device is connected but offline. Reconnect the USB cable, keep the phone unlocked, and retry."
    }
}

$TracePath = Resolve-TracePath $TraceFile
$SummaryPath = Resolve-TracePath $SummaryFile
$TraceDirectory = Split-Path -Parent $TracePath
if ($TraceDirectory) {
    New-Item -ItemType Directory -Force -Path $TraceDirectory | Out-Null
}

switch ($Action) {
    "check" {
        $adb = Find-Adb
        if ($adb) {
            Write-Host "adb.exe found: $adb"
            Invoke-AdbDevices $adb
        }
        else {
            Write-Warning "adb.exe not found in common Android SDK locations. Frida USB checks may still work if the phone and frida-server are already connected."
        }

        $arguments = @(
            $TraceScript,
            "--check-only",
            "--package", $Package,
            "--timeout-ms", "$TimeoutMs"
        )
        if ($FridaHost) {
            $arguments += @("--host", $FridaHost)
        }
        if ($DeviceId) {
            $arguments += @("--device-id", $DeviceId)
        }
        & $Python @arguments
        exit $LASTEXITCODE
    }

    "trace" {
        $arguments = @(
            $TraceScript,
            "--package", $Package,
            "--timeout-ms", "$TimeoutMs",
            "--out", $TracePath
        )
        if ($FridaHost) {
            $arguments += @("--host", $FridaHost)
        }
        if (-not $Spawn) {
            $arguments += "--attach"
        }
        if ($DeviceId) {
            $arguments += @("--device-id", $DeviceId)
        }

        Write-Host "Trace output: $TracePath"
        & $Python @arguments
        exit $LASTEXITCODE
    }

    "summarize" {
        if (-not (Test-Path $TracePath)) {
            throw "Trace file not found: $TracePath"
        }

        $arguments = @(
            $SummaryScript,
            $TracePath,
            "--output", $SummaryPath
        )
        if ($All) {
            $arguments += "--all"
        }

        Write-Host "Summary output: $SummaryPath"
        & $Python @arguments
        exit $LASTEXITCODE
    }
}