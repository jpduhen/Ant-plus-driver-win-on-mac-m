param(
  [string]$SourceDir = 'C:\temp\tacx\bridge_skeleton',
  [string]$OutDir = 'C:\temp\tacx\bridge_skeleton\build_nocmake'
)

$ErrorActionPreference = 'Stop'

$stub = Join-Path $SourceDir 'ant_bridge_stub.c'
$def  = Join-Path $SourceDir 'ant_bridge.def'
if (!(Test-Path $stub)) { throw "Missing file: $stub" }
if (!(Test-Path $def)) { throw "Missing file: $def" }

if (!(Get-Command cl.exe -ErrorAction SilentlyContinue)) {
  throw 'cl.exe not found. Open "x64 Native Tools Command Prompt" or "Developer PowerShell for VS" first.'
}
if (!(Get-Command link.exe -ErrorAction SilentlyContinue)) {
  throw 'link.exe not found. Open "x64 Native Tools Command Prompt" or "Developer PowerShell for VS" first.'
}

New-Item -ItemType Directory -Force -Path $OutDir | Out-Null
Push-Location $OutDir
try {
  cl.exe /nologo /LD "$stub" /link /NOLOGO /DEF:"$def" /OUT:ANT_WrappedLib.dll
  if (Test-Path (Join-Path $OutDir 'ANT_WrappedLib.dll')) {
    Write-Host "Built: $(Join-Path $OutDir 'ANT_WrappedLib.dll')" -ForegroundColor Green
  } else {
    throw 'Build command completed but ANT_WrappedLib.dll not found.'
  }
}
finally {
  Pop-Location
}
