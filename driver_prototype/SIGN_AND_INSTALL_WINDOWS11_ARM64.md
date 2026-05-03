# Nieuwe oplossing: test-signing + gesigneerde INF installeren

Je foutmelding laat twee blokkades zien:

1. `The third-party INF does not contain digital signature information` (pnputil blokkeert package).
2. `No compatible drivers` bij handmatige wizard als ongesigneerde/onjuiste package wordt gescand.

## Stap 0 — vereisten op Windows VM

Installeer op Windows 11 ARM64:
- Windows SDK (met `signtool.exe`)
- Windows Driver Kit (met `inf2cat.exe`)

## Stap 1 — test signing aanzetten en reboot

Admin CMD:

```bat
bcdedit /set testsigning on
shutdown /r /t 0
```

Na reboot moet "Test Mode" zichtbaar zijn op het bureaublad.

## Stap 2 — self-signed code signing certificaat maken

Admin PowerShell:

```powershell
$cert = New-SelfSignedCertificate -Type CodeSigningCert -Subject "CN=Tacx Test Driver" -CertStoreLocation "Cert:\LocalMachine\My"
$pwd = ConvertTo-SecureString -String "TacxTest123!" -Force -AsPlainText
Export-PfxCertificate -Cert $cert -FilePath C:\temp\tacx\tacx-test-signing.pfx -Password $pwd
Import-Certificate -FilePath C:\temp\tacx\tacx-test-signing.cer -CertStoreLocation Cert:\LocalMachine\Root
Import-Certificate -FilePath C:\temp\tacx\tacx-test-signing.cer -CertStoreLocation Cert:\LocalMachine\TrustedPublisher
```

> Als `.cer` ontbreekt, eerst exporteren:

```powershell
Export-Certificate -Cert $cert -FilePath C:\temp\tacx\tacx-test-signing.cer
```

## Stap 3 — catalogus genereren voor INF

Admin CMD (pas pad aan naar jouw SDK/WDK versie):

```bat
cd /d C:\temp\tacx
inf2cat /driver:. /os:10_RS5_ARM64
```

## Stap 4 — catalogus tekenen

Admin CMD:

```bat
signtool sign /fd sha256 /f C:\temp\tacx\tacx-test-signing.pfx /p TacxTest123! /tr http://timestamp.digicert.com /td sha256 C:\temp\tacx\tacx_winusb_arm64.cat
signtool sign /fd sha256 /f C:\temp\tacx\tacx-test-signing.pfx /p TacxTest123! /tr http://timestamp.digicert.com /td sha256 C:\temp\tacx\tacx_winusb_arm64_compat.cat
```

## Stap 5 — installeren

```bat
pnputil /add-driver C:\temp\tacx\tacx_winusb_arm64.inf /install
pnputil /add-driver C:\temp\tacx\tacx_winusb_arm64_compat.inf /install
pnputil /enum-drivers
pnputil /enum-devices /connected
```

## Stap 6 — als nog geen match

Gebruik Device Manager > Update Driver > Browse > map `C:\temp\tacx` en deel daarna opnieuw:

```powershell
Select-String -Path C:\Windows\INF\setupapi.dev.log -Pattern "VID_0FCF&PID_1008" -Context 0,30
```


## Snelle route: één script

In **Admin PowerShell**:

```powershell
Set-ExecutionPolicy -Scope Process Bypass
cd C:\temp\tacx
.\autosign_and_install.ps1 -DriverDir C:\temp\tacx -InstallCompat
```

Dit script doet automatisch: cert maken, `.cat` genereren, signeren en installeren.
