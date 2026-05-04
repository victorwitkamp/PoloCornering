param(
    [string]$Port = "COM10",
    [int]$Baud = 38400
)

$ErrorActionPreference = "Stop"
$RepoRoot = Split-Path -Parent $PSScriptRoot
$Timestamp = Get-Date -Format "yyyyMMdd_HHmmss"
$RunId = "cluster_needle_${Timestamp}_22A2_readonly"

python "$PSScriptRoot\scan_vag_uds_headers.py" `
    --port $Port `
    --baud $Baud `
    --timeout 2.5 `
    --headers 714 `
    --discovery-commands 22F187 `
    --detail-commands 2222A2,22F187,22F189,22F197,22F1A5 `
    --output-dir "$RepoRoot\obd-on-pc\logs" `
    --run-id $RunId
