# Nieuwe oplossing: test-signing + gesigneerde INF installeren

Je foutmelding laat twee blokkades zien:

1. `The third-party INF does not contain digital signature information` (pnputil blokkeert package).
2. `No compatible drivers` bij handmatige wizard als ongesigneerde/onjuiste package wordt gescand.

## Belangrijk: Secure Boot blokkeert `testsigning on`

Als je krijgt:

- `An error has occurred setting the element data`
- `The value is protected by Secure Boot policy`

...dan moet je in Parallels **Secure Boot uitzetten** voor deze VM.

Praktisch in Parallels (VM uitgeschakeld):

1. Open VM Configuration.
2. Check onder Security/Boot opties of **Secure Boot** aan staat en zet dit uit.
3. Let op: in Parallels zorgt vTPM meestal automatisch voor Secure Boot; mogelijk moet TPM tijdelijk uit voor testsigning.
4. Start VM opnieuw en probeer:

```bat
bcdedit /set testsigning on
shutdown /r /t 0
```

## Stap 0 — SDK en WDK installeren (Windows 11 ARM64)

### Windows SDK

1. Open: https://learn.microsoft.com/windows/apps/windows-sdk/downloads
2. Download de **Windows 11 SDK Installer**.
3. Installeer met standaardopties (zorg dat `signtool.exe` beschikbaar komt).

### Windows Driver Kit (WDK)

1. Open: https://learn.microsoft.com/en-us/windows-hardware/drivers/download-the-wdk
2. Installeer WDK die hoort bij je SDK-versie.
3. Open daarna een **Developer PowerShell/CMD** waar `inf2cat.exe` in PATH staat.

### Snelle check tools

```powershell
where signtool
where inf2cat
```


Als `inf2cat` niet herkend wordt:

1. Open **x64 Native Tools / Developer Command Prompt** (SDK/WDK prompt).
2. Of voeg tijdelijk PATH toe in PowerShell:

```powershell
$kitBin = Get-ChildItem 'C:\Program Files (x86)\Windows Kits\10\bin' -Directory | Sort-Object Name -Descending | Select-Object -First 1
$env:Path += ';' + (Join-Path $kitBin.FullName 'x64')
where inf2cat
where signtool
```

3. Voor permanente PATH (nieuwe sessies):

```powershell
setx PATH "$($env:PATH);$($kitBin.FullName)\x64"
```


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
Export-Certificate -Cert $cert -FilePath C:\temp\tacx\tacx-test-signing.cer
Import-Certificate -FilePath C:\temp\tacx\tacx-test-signing.cer -CertStoreLocation Cert:\LocalMachine\Root
Import-Certificate -FilePath C:\temp\tacx\tacx-test-signing.cer -CertStoreLocation Cert:\LocalMachine\TrustedPublisher
```

## Stap 3 — catalogus genereren voor INF

Admin CMD:

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

## Snelle route: één script

In **Admin PowerShell**:

```powershell
Set-ExecutionPolicy -Scope Process Bypass
cd C:\temp\tacx
.\autosign_and_install.ps1 -DriverDir C:\temp\tacx -InstallCompat
```

## Als nog geen match

```powershell
Select-String -Path C:\Windows\INF\setupapi.dev.log -Pattern "VID_0FCF&PID_1008" -Context 0,30
```
