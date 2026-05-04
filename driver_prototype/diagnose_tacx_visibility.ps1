param(
    [string]$InstancePattern = 'VID_0FCF&PID_1008'
)

$ErrorActionPreference = 'Continue'

Write-Host '=== Tacx visibility diagnose ===' -ForegroundColor Cyan

$dev = Get-PnpDevice | Where-Object { $_.InstanceId -like "*${InstancePattern}*" }
if (-not $dev) {
    Write-Host "Geen device met pattern gevonden: $InstancePattern" -ForegroundColor Red
    exit 1
}

$dev | Format-List Status,Class,FriendlyName,InstanceId,Present,Problem,ConfigManagerErrorCode

foreach ($d in $dev) {
    Write-Host "`n--- Properties for $($d.InstanceId) ---" -ForegroundColor Yellow
    Get-PnpDeviceProperty -InstanceId $d.InstanceId | Where-Object {
        $_.KeyName -match 'DEVPKEY_Device_(Service|Driver|ClassGuid|Manufacturer|HardwareIds|CompatibleIds)'
    } | Select-Object KeyName, Data | Format-Table -AutoSize
}

Write-Host "`n--- WinUSB service status ---" -ForegroundColor Yellow
Get-Service WinUSB -ErrorAction SilentlyContinue | Format-List Name,Status,StartType

Write-Host "`n--- USB devices (PnPUtil connected) ---" -ForegroundColor Yellow
pnputil /enum-devices /connected

Write-Host "`n--- Driver packages containing Tacx/ANT ---" -ForegroundColor Yellow
pnputil /enum-drivers | Select-String -Pattern 'Tacx|ANT\+|WinUSB|0FCF|1008' -Context 0,2

Write-Host "`n--- SetupAPI snippet ---" -ForegroundColor Yellow
Select-String -Path C:\Windows\INF\setupapi.dev.log -Pattern 'VID_0FCF&PID_1008' -Context 0,10 | Select-Object -Last 40

Write-Host "`nKlaar. Deel deze output om de volgende stap (GUID/filter/driver binding) te bepalen." -ForegroundColor Green
