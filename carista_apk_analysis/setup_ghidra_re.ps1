param(
    [switch]$RunHeadless,
    [switch]$ExportTargets,
    [switch]$CleanProject,
    [string]$HeadlessMaxMem = "8G",
    [string]$ExportDir = "",
    [switch]$Force
)

$ErrorActionPreference = "Stop"
$ProgressPreference = "SilentlyContinue"

$ScriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$RepoRoot = Resolve-Path (Join-Path $ScriptDir "..")
$ToolsDir = Join-Path $RepoRoot "tools"
$DownloadDir = Join-Path $ToolsDir "downloads"
$GhidraDir = Join-Path $ToolsDir "ghidra"
$JdkDir = Join-Path $ToolsDir "jdk21"
$ExtractDir = Join-Path $ScriptDir "extracted"
$XapkPath = Join-Path $ScriptDir "reacquire_20260424\carista_9.8.2.xapk"
$LibPath = Join-Path $ExtractDir "libCarista.so"
$ProjectDir = Join-Path $ScriptDir "ghidra_project"
$ProjectName = "CaristaNative"
$GhidraScriptsDir = Join-Path $ScriptDir "ghidra_scripts"
if (-not $ExportDir) {
    $ExportDir = Join-Path $ScriptDir "ghidra_exports"
}

function Ensure-Directory($Path) {
    if (-not (Test-Path $Path)) {
        New-Item -ItemType Directory -Path $Path | Out-Null
    }
}

function Download-File($Uri, $OutFile) {
    if ((Test-Path $OutFile) -and -not $Force) {
        Write-Host "Using existing $(Split-Path -Leaf $OutFile)"
        return
    }

    Write-Host "Downloading $Uri"
    Invoke-WebRequest -Uri $Uri -OutFile $OutFile -Headers @{ "User-Agent" = "PoloCornering-Ghidra-Setup" }
}

function First-ChildDirectory($Path) {
    Get-ChildItem -Path $Path -Directory | Select-Object -First 1
}

function Invoke-GhidraHeadless($HeadlessArgs) {
    $VmArgs = "-XX:ParallelGCThreads=2 -XX:CICompilerCount=2 -Djava.awt.headless=true"
    & $LaunchBat "fg" "jdk" "Ghidra-Headless" $HeadlessMaxMem $VmArgs "ghidra.app.util.headless.AnalyzeHeadless" @HeadlessArgs
    if ($LASTEXITCODE -ne 0) {
        throw "Ghidra headless failed with exit code $LASTEXITCODE"
    }
}

Ensure-Directory $ToolsDir
Ensure-Directory $DownloadDir
Ensure-Directory $ExtractDir

Write-Host "Resolving latest Ghidra release..."
$GhidraRelease = Invoke-RestMethod -Uri "https://api.github.com/repos/NationalSecurityAgency/ghidra/releases/latest" -Headers @{ "User-Agent" = "PoloCornering-Ghidra-Setup" }
$GhidraAsset = $GhidraRelease.assets | Where-Object { $_.name -match '^ghidra_.*_PUBLIC_.*\.zip$' } | Select-Object -First 1
if (-not $GhidraAsset) {
    throw "Could not find a Ghidra PUBLIC zip asset in the latest NSA/Ghidra release."
}

$GhidraZip = Join-Path $DownloadDir $GhidraAsset.name
Download-File -Uri $GhidraAsset.browser_download_url -OutFile $GhidraZip

if ((Test-Path $GhidraDir) -and $Force) {
    Remove-Item -Recurse -Force $GhidraDir
}

if (-not (Test-Path $GhidraDir)) {
    $GhidraTmp = Join-Path $ToolsDir "ghidra_extract"
    if (Test-Path $GhidraTmp) { Remove-Item -Recurse -Force $GhidraTmp }
    Ensure-Directory $GhidraTmp
    Write-Host "Extracting Ghidra..."
    Expand-Archive -Path $GhidraZip -DestinationPath $GhidraTmp -Force
    $ExtractedGhidra = First-ChildDirectory $GhidraTmp
    if (-not $ExtractedGhidra) { throw "Ghidra zip did not contain a top-level directory." }
    Move-Item -Path $ExtractedGhidra.FullName -Destination $GhidraDir
    Remove-Item -Recurse -Force $GhidraTmp
} else {
    Write-Host "Using existing Ghidra directory"
}

Write-Host "Resolving portable Temurin JDK 21..."
$JdkAssets = Invoke-RestMethod -Uri "https://api.adoptium.net/v3/assets/latest/21/hotspot?architecture=x64&image_type=jdk&os=windows&vendor=eclipse"
$JdkPackage = $JdkAssets[0].binary.package
if (-not $JdkPackage.link) {
    throw "Could not resolve a Windows x64 Temurin JDK 21 package."
}

$JdkZip = Join-Path $DownloadDir $JdkPackage.name
Download-File -Uri $JdkPackage.link -OutFile $JdkZip

if ((Test-Path $JdkDir) -and $Force) {
    Remove-Item -Recurse -Force $JdkDir
}

if (-not (Test-Path $JdkDir)) {
    $JdkTmp = Join-Path $ToolsDir "jdk_extract"
    if (Test-Path $JdkTmp) { Remove-Item -Recurse -Force $JdkTmp }
    Ensure-Directory $JdkTmp
    Write-Host "Extracting JDK 21..."
    Expand-Archive -Path $JdkZip -DestinationPath $JdkTmp -Force
    $ExtractedJdk = First-ChildDirectory $JdkTmp
    if (-not $ExtractedJdk) { throw "JDK zip did not contain a top-level directory." }
    Move-Item -Path $ExtractedJdk.FullName -Destination $JdkDir
    Remove-Item -Recurse -Force $JdkTmp
} else {
    Write-Host "Using existing JDK directory"
}

if (-not (Test-Path $XapkPath)) {
    throw "Missing XAPK at $XapkPath"
}

if ((-not (Test-Path $LibPath)) -or $Force) {
    Add-Type -AssemblyName System.IO.Compression.FileSystem
    Write-Host "Extracting libCarista.so from XAPK..."
    $Xapk = [System.IO.Compression.ZipFile]::OpenRead($XapkPath)
    try {
        $ArmApkEntry = $Xapk.Entries | Where-Object { $_.FullName -eq "config.armeabi_v7a.apk" } | Select-Object -First 1
        if (-not $ArmApkEntry) { throw "config.armeabi_v7a.apk not found in XAPK." }
        $ArmApkStream = $ArmApkEntry.Open()
        try {
            $Memory = New-Object System.IO.MemoryStream
            $ArmApkStream.CopyTo($Memory)
            $Memory.Position = 0
            $ArmApk = New-Object System.IO.Compression.ZipArchive($Memory, [System.IO.Compression.ZipArchiveMode]::Read)
            try {
                $LibEntry = $ArmApk.Entries | Where-Object { $_.FullName -eq "lib/armeabi-v7a/libCarista.so" } | Select-Object -First 1
                if (-not $LibEntry) { throw "lib/armeabi-v7a/libCarista.so not found in config APK." }
                $LibStream = $LibEntry.Open()
                try {
                    $OutStream = [System.IO.File]::Open($LibPath, [System.IO.FileMode]::Create, [System.IO.FileAccess]::Write)
                    try { $LibStream.CopyTo($OutStream) } finally { $OutStream.Dispose() }
                } finally {
                    $LibStream.Dispose()
                }
            } finally {
                $ArmApk.Dispose()
                $Memory.Dispose()
            }
        } finally {
            $ArmApkStream.Dispose()
        }
    } finally {
        $Xapk.Dispose()
    }
} else {
    Write-Host "Using existing extracted libCarista.so"
}

$GhidraRun = Join-Path $GhidraDir "ghidraRun.bat"
$AnalyzeHeadless = Join-Path $GhidraDir "support\analyzeHeadless.bat"
$LaunchBat = Join-Path $GhidraDir "support\launch.bat"
$JavaExe = Join-Path $JdkDir "bin\java.exe"

if (-not (Test-Path $GhidraRun)) { throw "Missing $GhidraRun" }
if (-not (Test-Path $AnalyzeHeadless)) { throw "Missing $AnalyzeHeadless" }
if (-not (Test-Path $LaunchBat)) { throw "Missing $LaunchBat" }
if (-not (Test-Path $JavaExe)) { throw "Missing $JavaExe" }
if ($ExportTargets -and -not (Test-Path $GhidraScriptsDir)) { throw "Missing $GhidraScriptsDir" }

$env:JAVA_HOME = $JdkDir
$env:PATH = "$JdkDir\bin;$env:PATH"

Write-Host ""
Write-Host "Ghidra:        $GhidraDir"
Write-Host "JDK:           $JdkDir"
Write-Host "libCarista.so: $LibPath"
Write-Host "Ghidra UI:     $GhidraRun"
Write-Host "Headless:      $AnalyzeHeadless"

if ($RunHeadless) {
    if ($CleanProject -and (Test-Path $ProjectDir)) {
        Write-Host "Removing existing Ghidra project: $ProjectDir"
        Remove-Item -Recurse -Force $ProjectDir
    }
    Ensure-Directory $ProjectDir
    Write-Host "Running Ghidra headless import/analyze with heap $HeadlessMaxMem. This can take a while..."
    Invoke-GhidraHeadless @($ProjectDir, $ProjectName, "-import", $LibPath, "-processor", "ARM:LE:32:v7", "-overwrite", "-analysisTimeoutPerFile", "1800")
}

if ($ExportTargets) {
    if (-not (Test-Path $ProjectDir)) {
        throw "Missing Ghidra project at $ProjectDir. Run with -RunHeadless first."
    }
    Ensure-Directory $ExportDir
    Write-Host "Exporting target decompilation to $ExportDir"
    Invoke-GhidraHeadless @($ProjectDir, $ProjectName, "-process", "libCarista.so", "-readOnly", "-noanalysis", "-scriptPath", $GhidraScriptsDir, "-postScript", "ExportCaristaTargets.java", $ExportDir)
}