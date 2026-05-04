param(
  [string]$InfPath = 'C:\temp\tacx\ant_usb2_drivers\ANT_LibUsb.inf'
)

$ErrorActionPreference = 'Stop'
if (!(Test-Path $InfPath)) { throw "INF not found: $InfPath" }

$content = Get-Content -Raw $InfPath
if ($content -match '(?i)3C5E1462-5695-4E18-876B-F3F3D08AAF18') {
  Write-Host 'GUID already present, no patch needed.' -ForegroundColor Green
  exit 0
}

# Ensure DeviceInterfaceGUIDs AddReg exists in install section.
if ($content -match '(?im)^\[ANT_LibUsb\.NT\]') {
  $content = $content -replace '(?im)^\[ANT_LibUsb\.NT\]\r?\n', "[ANT_LibUsb.NT]`r`nAddReg = Tacx_DeviceInterface_AddReg`r`n"
} else {
  throw 'Expected section [ANT_LibUsb.NT] not found; patch script requires this section.'
}

$content += "`r`n[Tacx_DeviceInterface_AddReg]`r`n" + 'HKR,,DeviceInterfaceGUIDs,0x10000,"{3C5E1462-5695-4E18-876B-F3F3D08AAF18}"' + "`r`n"

Set-Content -Path $InfPath -Value $content -NoNewline
Write-Host "Patched: $InfPath" -ForegroundColor Green
Write-Host 'Now run: pnputil /add-driver <INF> /install' -ForegroundColor Cyan
