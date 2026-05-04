# Commando's (achter elkaar) voor Windows 11 ARM64

Open **PowerShell als Administrator** en voer exact dit uit:

```powershell
Set-ExecutionPolicy -Scope Process Bypass
cd C:\temp\tacx
$drivers = pnputil /enum-drivers | Out-String
$blocks = $drivers -split "`r?`n`r?`n"
$targets = foreach($b in $blocks){ if($b -match 'Published Name\s*:\s*(oem\d+\.inf)' -and $b -match '(?i)Tacx ANT\+ USB Dongle'){ $Matches[1] } }
foreach($oem in $targets){ pnputil /delete-driver $oem /uninstall /force }
pnputil /add-driver C:\temp\tacx\tacx_winusb_arm64.inf /install
pnputil /enum-devices /connected
pnputil /enum-drivers
```

Als Tacx software de dongle nog niet ziet, direct daarna:

```powershell
pnputil /add-driver C:\temp\tacx\tacx_winusb_arm64_compat.inf /install
pnputil /enum-devices /connected
pnputil /enum-drivers
```

## Als je weer Code 28 ziet

Voer dit uit en deel de uitkomst:

```powershell
Select-String -Path C:\Windows\INF\setupapi.dev.log -Pattern "VID_0FCF&PID_1008" -Context 0,20
```
