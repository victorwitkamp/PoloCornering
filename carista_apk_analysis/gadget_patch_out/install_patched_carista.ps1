param(
    [switch]$UninstallFirst
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

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

$adb = Find-Adb
if (-not $adb) {
    throw "adb.exe not found in PATH or common Android SDK locations. Install platform-tools first."
}

function Invoke-Adb([string[]]$Arguments) {
    & $adb @Arguments
    if ($LASTEXITCODE -ne 0) {
        throw "adb command failed ($LASTEXITCODE): $($Arguments -join ' ')"
    }
}

$base = "C:\Users\victo\Downloads\2026-04-14 17-26-52\carista_apk_analysis\gadget_patch_out\signed\com.prizmos.carista.apk"
$arm = "C:\Users\victo\Downloads\2026-04-14 17-26-52\carista_apk_analysis\gadget_patch_out\signed\config.armeabi_v7a.apk"
$hdpi = "C:\Users\victo\Downloads\2026-04-14 17-26-52\carista_apk_analysis\gadget_patch_out\signed\config.hdpi.apk"

if ($UninstallFirst) {
    Invoke-Adb @("uninstall", "com.prizmos.carista")
}

Invoke-Adb @("install-multiple", $base, $arm, $hdpi)
Invoke-Adb @("forward", "tcp:27042", "tcp:27042")

Write-Host "Forwarded tcp:27042 -> tcp:27042."
Write-Host "Next: .\carista_apk_analysis\run_carista_cornering_capture.ps1 -Action trace -FridaHost 127.0.0.1:27042"
