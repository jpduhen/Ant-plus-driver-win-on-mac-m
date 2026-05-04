param(
  [string]$TacxDir = 'C:\Program Files (x86)\Tacx\TacxTrainersoftware4'
)

$ErrorActionPreference = 'Stop'
$target = Join-Path $TacxDir 'ANT_WrappedLib.dll'
$backup = Join-Path $TacxDir 'ANT_WrappedLib.original.dll'

if (!(Test-Path $backup)) { throw "Backup not found: $backup" }
Copy-Item $backup $target -Force
Write-Host "Restored original DLL: $target" -ForegroundColor Green
