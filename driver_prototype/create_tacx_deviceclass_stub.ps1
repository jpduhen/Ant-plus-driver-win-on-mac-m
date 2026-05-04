param(
  [string]$InstanceId = 'USB\VID_0FCF&PID_1008\123',
  [string]$Guid = '{3c5e1462-5695-4e18-876b-f3f3d08aaf18}'
)

$ErrorActionPreference = 'Stop'
$base = "HKLM:\SYSTEM\CurrentControlSet\Control\DeviceClasses\$Guid"
if (!(Test-Path $base)) { New-Item -Path $base -Force | Out-Null }

# Build legacy-style symbolic link name used by many USB stacks.
$sym = "##?#" + ($InstanceId -replace '\\','#') + "#$Guid"
$devKey = Join-Path $base $sym
if (!(Test-Path $devKey)) { New-Item -Path $devKey -Force | Out-Null }
New-ItemProperty -Path $devKey -Name '(Default)' -PropertyType String -Value '' -Force | Out-Null
New-ItemProperty -Path $devKey -Name 'DeviceInstance' -PropertyType String -Value $InstanceId -Force | Out-Null

$control = Join-Path $devKey 'Control'
if (!(Test-Path $control)) { New-Item -Path $control -Force | Out-Null }
New-ItemProperty -Path $control -Name 'Linked' -PropertyType DWord -Value 1 -Force | Out-Null

Write-Host "Created/updated: $base" -ForegroundColor Green
Write-Host "Created/updated: $devKey" -ForegroundColor Green
