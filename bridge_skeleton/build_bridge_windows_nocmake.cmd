@echo off
setlocal

set SRC=%~1
set OUT=%~2
if "%SRC%"=="" set SRC=C:\temp\tacx\bridge_skeleton
if "%OUT%"=="" set OUT=C:\temp\tacx\bridge_skeleton\build_nocmake

if not exist "%SRC%\ant_bridge_stub.c" (
  echo Missing file: %SRC%\ant_bridge_stub.c
  exit /b 1
)
if not exist "%SRC%\ant_bridge.def" (
  echo Missing file: %SRC%\ant_bridge.def
  exit /b 1
)

where cl.exe >nul 2>nul
if errorlevel 1 (
  echo cl.exe not found. Open "Developer Command Prompt for VS" first.
  exit /b 1
)
where link.exe >nul 2>nul
if errorlevel 1 (
  echo link.exe not found. Open "Developer Command Prompt for VS" first.
  exit /b 1
)

if not exist "%OUT%" mkdir "%OUT%"
pushd "%OUT%"
cl.exe /nologo /LD "%SRC%\ant_bridge_stub.c" /link /NOLOGO /DEF:"%SRC%\ant_bridge.def" /OUT:ANT_WrappedLib.dll
set RC=%ERRORLEVEL%
popd

if %RC% neq 0 exit /b %RC%

echo Built: %OUT%\ANT_WrappedLib.dll
endlocal
