param(
  [string]$BuiltDll = 'C:\temp\tacx\bridge_skeleton\build_nocmake\ANT_WrappedLib.dll',
  [string]$TacxDir = 'C:\Program Files (x86)\Tacx\TacxTrainersoftware4'
)

$ErrorActionPreference = 'Stop'
if (!(Test-Path $BuiltDll)) { throw "Built DLL not found: $BuiltDll" }
if (!(Test-Path $TacxDir)) { throw "TacxDir not found: $TacxDir" }

$target = Join-Path $TacxDir 'ANT_WrappedLib.dll'
$backup = Join-Path $TacxDir 'ANT_WrappedLib.original.dll'

if (!(Test-Path $target)) { throw "Original DLL not found: $target" }
if (!(Test-Path $backup)) {
  Copy-Item $target $backup -Force
  Write-Host "Backup created: $backup" -ForegroundColor Green
} else {
  Write-Host "Backup already exists: $backup" -ForegroundColor Yellow
}

Copy-Item $BuiltDll $target -Force
Write-Host "Deployed bridge DLL to: $target" -ForegroundColor Green
Write-Host 'Start Tacx and capture DebugView/ProcMon logs for exported function calls.' -ForegroundColor Cyan
