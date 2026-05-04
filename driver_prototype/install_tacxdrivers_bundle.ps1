param(
  [string]$DriverRoot = 'C:\temp\tacx\TacxDrivers',
  [string]$InstanceId = 'USB\VID_0FCF&PID_1008\123'
)

$ErrorActionPreference = 'Stop'
if (!(Test-Path $DriverRoot)) { throw "DriverRoot not found: $DriverRoot" }

Write-Host "Staging all INF files under: $DriverRoot" -ForegroundColor Cyan
pnputil /add-driver "$DriverRoot\*.inf" /subdirs | Out-Host

Write-Host 'Re-enumerating target device...' -ForegroundColor Cyan
pnputil /remove-device $InstanceId | Out-Host
pnputil /scan-devices | Out-Host

Write-Host 'Current device status:' -ForegroundColor Cyan
Get-PnpDevice -InstanceId $InstanceId | Format-List Status,Class,FriendlyName,InstanceId | Out-Host

Write-Host 'Related published drivers (Dynastream/Jungo/Tacx):' -ForegroundColor Cyan
pnputil /enum-drivers | findstr /i "dynastream jungo tacx ant_libusb" | Out-Host
