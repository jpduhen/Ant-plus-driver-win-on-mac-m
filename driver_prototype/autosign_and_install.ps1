param(
    [string]$DriverDir = 'C:\temp\tacx',
    [string]$CertSubject = 'CN=Tacx Test Driver',
    [string]$PfxPassword = 'TacxTest123!',
    [switch]$InstallCompat
)

$ErrorActionPreference = 'Stop'

$InfA = Join-Path $DriverDir 'tacx_winusb_arm64.inf'
$InfB = Join-Path $DriverDir 'tacx_winusb_arm64_compat.inf'
$CatA = Join-Path $DriverDir 'tacx_winusb_arm64.cat'
$CatB = Join-Path $DriverDir 'tacx_winusb_arm64_compat.cat'
$Pfx  = Join-Path $DriverDir 'tacx-test-signing.pfx'
$Cer  = Join-Path $DriverDir 'tacx-test-signing.cer'

function Require-File([string]$Path) {
    if (-not (Test-Path $Path)) { throw "Bestand ontbreekt: $Path" }
}

function Find-Tool([string]$ToolName) {
    $cmd = Get-Command $ToolName -ErrorAction SilentlyContinue
    if ($cmd) { return $cmd.Source }
    return $null
}

Require-File $InfA
Require-File $InfB

$inf2cat = Find-Tool 'inf2cat.exe'
$signtool = Find-Tool 'signtool.exe'
if (-not $inf2cat) { throw 'inf2cat.exe niet gevonden. Installeer Windows Driver Kit (WDK) en open Developer PowerShell.' }
if (-not $signtool) { throw 'signtool.exe niet gevonden. Installeer Windows SDK en open Developer PowerShell.' }

Write-Host '[1/6] Zelf-ondertekend certificaat maken...' -ForegroundColor Cyan
$cert = New-SelfSignedCertificate -Type CodeSigningCert -Subject $CertSubject -CertStoreLocation 'Cert:\LocalMachine\My'
$pwd = ConvertTo-SecureString -String $PfxPassword -AsPlainText -Force
Export-PfxCertificate -Cert $cert -FilePath $Pfx -Password $pwd | Out-Null
Export-Certificate -Cert $cert -FilePath $Cer | Out-Null
Import-Certificate -FilePath $Cer -CertStoreLocation 'Cert:\LocalMachine\Root' | Out-Null
Import-Certificate -FilePath $Cer -CertStoreLocation 'Cert:\LocalMachine\TrustedPublisher' | Out-Null

Write-Host '[2/6] Catalogusbestanden genereren (inf2cat)...' -ForegroundColor Cyan
Push-Location $DriverDir
& $inf2cat /driver:. /os:10_RS5_ARM64
Pop-Location

Require-File $CatA
Require-File $CatB

Write-Host '[3/6] Catalogusbestanden signeren (signtool)...' -ForegroundColor Cyan
& $signtool sign /fd sha256 /f $Pfx /p $PfxPassword /tr http://timestamp.digicert.com /td sha256 $CatA
& $signtool sign /fd sha256 /f $Pfx /p $PfxPassword /tr http://timestamp.digicert.com /td sha256 $CatB

Write-Host '[4/6] Baseline driver installeren...' -ForegroundColor Cyan
pnputil /add-driver $InfA /install

if ($InstallCompat) {
    Write-Host '[5/6] Compat driver installeren...' -ForegroundColor Cyan
    pnputil /add-driver $InfB /install
} else {
    Write-Host '[5/6] Compat driver overgeslagen (gebruik -InstallCompat om ook te installeren).' -ForegroundColor Yellow
}

Write-Host '[6/6] Status dump...' -ForegroundColor Cyan
pnputil /enum-devices /connected
pnputil /enum-drivers

Write-Host 'Klaar. Als het nog niet werkt, stuur setupapi.dev.log regels rond VID_0FCF&PID_1008.' -ForegroundColor Green
