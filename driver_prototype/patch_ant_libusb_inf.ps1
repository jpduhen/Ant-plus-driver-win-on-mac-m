param(
  [string]$InfPath = 'C:\temp\tacx\ant_usb2_drivers\ANT_LibUsb.inf',
  [string]$OutPath = ''
)

$ErrorActionPreference = 'Stop'
if (!(Test-Path $InfPath)) { throw "INF not found: $InfPath" }

if (-not $OutPath) {
  $dir = Split-Path -Parent $InfPath
  $name = [System.IO.Path]::GetFileNameWithoutExtension($InfPath)
  $ext = [System.IO.Path]::GetExtension($InfPath)
  $OutPath = Join-Path $dir ("${name}_patched${ext}")
}

$content = Get-Content -Raw $InfPath
if ($content -match '(?i)3C5E1462-5695-4E18-876B-F3F3D08AAF18') {
  Write-Host 'GUID already present, no patch needed.' -ForegroundColor Green
  Copy-Item $InfPath $OutPath -Force
  Write-Host "Copied original to: $OutPath" -ForegroundColor Cyan
  exit 0
}

# Accept multiple install section naming variants seen in legacy INF files.
$sectionCandidates = @(
  'ANT_LibUsb.NT',
  'ANT_LibUsb',
  'LIBUSB_WIN32_DEV.NT',
  'LIBUSB_WIN32_DEV'
)

$patched = $false
foreach ($section in $sectionCandidates) {
  $escaped = [Regex]::Escape($section)
  if ($content -match "(?im)^\[$escaped\]") {
    $content = $content -replace "(?im)^\[$escaped\]\r?\n", "[$section]`r`nAddReg = Tacx_DeviceInterface_AddReg`r`n"
    $patched = $true
    Write-Host "Patched install section: [$section]" -ForegroundColor Cyan
    break
  }
}

if (-not $patched) {
  throw 'Expected install section not found (tried ANT_LibUsb.NT, ANT_LibUsb, LIBUSB_WIN32_DEV.NT, LIBUSB_WIN32_DEV). Inspect INF section names and update script candidates.'
}

$content += "`r`n[Tacx_DeviceInterface_AddReg]`r`n" + 'HKR,,DeviceInterfaceGUIDs,0x10000,"{3C5E1462-5695-4E18-876B-F3F3D08AAF18}"' + "`r`n"

Set-Content -Path $OutPath -Value $content -NoNewline
Write-Host "Patched INF written to: $OutPath" -ForegroundColor Green
Write-Host "Now run: pnputil /add-driver $OutPath /install" -ForegroundColor Cyan
