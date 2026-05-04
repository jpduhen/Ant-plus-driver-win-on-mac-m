param(
  [string]$SourceDir = 'C:\temp\tacx\bridge_skeleton',
  [string]$BuildDir = 'C:\temp\tacx\bridge_skeleton\build',
  [string]$Config = 'Release'
)

$ErrorActionPreference = 'Stop'

if (!(Test-Path $SourceDir)) { throw "SourceDir not found: $SourceDir" }
if (!(Test-Path (Join-Path $SourceDir 'CMakeLists.txt'))) { throw 'CMakeLists.txt not found in SourceDir.' }
if (!(Test-Path (Join-Path $SourceDir 'ant_bridge_stub.c'))) { throw 'ant_bridge_stub.c not found in SourceDir.' }
if (!(Test-Path (Join-Path $SourceDir 'ant_bridge.def'))) { throw 'ant_bridge.def not found in SourceDir.' }

if (!(Get-Command cmake -ErrorAction SilentlyContinue)) {
  throw 'cmake not found. Install CMake or use build_bridge_windows_nocmake.ps1 from a VS Developer shell.'
}

cmake -S $SourceDir -B $BuildDir -A ARM64
cmake --build $BuildDir --config $Config

$built = Join-Path $BuildDir "$Config\ANT_WrappedLib.dll"
if (Test-Path $built) {
  Write-Host "Built: $built" -ForegroundColor Green
} else {
  Write-Host "Build completed but DLL not found at expected path: $built" -ForegroundColor Yellow
}
