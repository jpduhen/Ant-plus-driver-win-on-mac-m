param(
    [string]$TacxDir = 'C:\Program Files (x86)\Tacx\TacxTrainersoftware4',
    [string]$SourceRoot = 'C:\temp\tacx'
)

$ErrorActionPreference = 'Stop'

Write-Host 'Zoeken naar libusb0.dll...' -ForegroundColor Cyan
$candidates = @()
if (Test-Path $SourceRoot) {
    $candidates += Get-ChildItem -Path $SourceRoot -Recurse -Include 'libusb0.dll','libusb0_x86.dll' -File -ErrorAction SilentlyContinue
}

if (-not $candidates -or $candidates.Count -eq 0) {
    Write-Host 'Geen libusb0.dll gevonden onder SourceRoot.' -ForegroundColor Yellow
    Write-Host 'Plaats een 32-bit libusb0.dll in C:\temp\tacx\runtime\ en run dit script opnieuw.' -ForegroundColor Yellow
    exit 1
}

$preferred = $candidates | Where-Object { $_.Name -ieq 'libusb0_x86.dll' } | Select-Object -First 1
if (-not $preferred) {
    $preferred = $candidates | Where-Object { $_.FullName -match '(?i)x86' } | Select-Object -First 1
}
$lib = if ($preferred) { $preferred } else { $candidates | Sort-Object Length -Descending | Select-Object -First 1 }
Write-Host "Gebruik: $($lib.FullName)" -ForegroundColor Green

if (-not (Test-Path $TacxDir)) {
    throw "Tacx map niet gevonden: $TacxDir"
}

$target1 = Join-Path $TacxDir 'libusb0.dll'
Copy-Item $lib.FullName $target1 -Force
Write-Host "Gekopieerd naar: $target1" -ForegroundColor Green

$syswow = 'C:\Windows\SysWOW64\libusb0.dll'
Copy-Item $lib.FullName $syswow -Force
Write-Host "Gekopieerd naar: $syswow" -ForegroundColor Green

Write-Host 'Klaar. Start Tacx opnieuw en test detectie.' -ForegroundColor Cyan
