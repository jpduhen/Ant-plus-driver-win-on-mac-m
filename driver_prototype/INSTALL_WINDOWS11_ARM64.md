# Installatieprototype: Tacx ANT+ via WinUSB op Windows 11 ARM64

Dit is een **eerste technische proef** om te testen of de Tacx T2018 dongle in jouw VM aanspreekbaar wordt zonder de oude kernel-driver.

## Je huidige fout (Code 28)

Als `pnputil /enum-devices /connected` toont:

- `Class Name: Unknown`
- `Problem Code: 28 (CM_PROB_FAILED_INSTALL)`

...dan is er wel een device-match geprobeerd, maar de driverinstallatie is mislukt.

## Voorwaarden

- Parallels USB passthrough staat op **Connect to Windows** voor de dongle.
- Device zichtbaar als `USB\VID_0FCF&PID_1008` in Device Manager.
- Je draait deze stappen in een **Administrator PowerShell** of **Administrator Command Prompt**.

## Bestanden kopiëren

Plaats deze bestanden op Windows, bijvoorbeeld in `C:\temp\tacx\`:

- `tacx_winusb_arm64.inf`
- `tacx_winusb_arm64_compat.inf`
- `manage_tacx_driver.ps1`

## Stap 1: oude mislukte prototype-installaties opruimen

```powershell
Set-ExecutionPolicy -Scope Process Bypass
cd C:\temp\tacx
.\manage_tacx_driver.ps1 -Action remove
```

## Stap 2: baseline installeren

```powershell
.\manage_tacx_driver.ps1 -Action install-a
```

## Stap 3: als Tacx software nog niets ziet, compat installeren

```powershell
.\manage_tacx_driver.ps1 -Action install-b
```

## Handmatige fallback (zonder script)

Variant A:

```bat
pnputil /add-driver C:\temp\tacx\tacx_winusb_arm64.inf /install
```

Variant B:

```bat
pnputil /add-driver C:\temp\tacx\tacx_winusb_arm64_compat.inf /install
```

Status:

```bat
pnputil /enum-devices /connected
pnputil /enum-drivers
```

## Als installatie nog steeds mislukt

1. Open `C:\Windows\INF\setupapi.dev.log`.
2. Zoek op `VID_0FCF&PID_1008`.
3. Deel het laatste blok met `!!!` regels (dat geeft de exacte installfout).

## Signing-opmerking

Deze INF's zijn niet gesigneerd. Voor een proof-of-concept kun je testsigning gebruiken. In productie moet de driver officieel gesigneerd worden.


## Driver geïnstalleerd maar Tacx software ziet niets

Dit betekent meestal dat de app niet alleen op hardware-ID zoekt, maar op:

- specifieke service/drivernaam
- specifieke Device Interface GUID
- of een legacy API-pad uit de originele Tacx/ANT stack

Draai dan (met execution policy bypass voor deze sessie):

```powershell
Set-ExecutionPolicy -Scope Process Bypass -Force
cd C:\temp\tacx
.\diagnose_tacx_visibility.ps1
```

Als zelfs dat geblokkeerd wordt, run direct via powershell.exe:

```powershell
powershell.exe -NoProfile -ExecutionPolicy Bypass -File C:\temp\tacx\diagnose_tacx_visibility.ps1
```

Optioneel (éénmalig) voor gedownloade scripts:

```powershell
Unblock-File C:\temp\tacx\diagnose_tacx_visibility.ps1
```

Deel de output; dan kunnen we gericht aanpassen (bijv. interface GUID, service-binding of bridge-laag).


## PowerShell output kopiëren (als Ctrl+C niet werkt)

In Windows Terminal/PowerShell wordt `Ctrl+C` gebruikt om een commando te stoppen, niet om te kopiëren.

Gebruik één van deze opties:

1. **Markeer met muis** en druk `Enter` (kopieert selectie).
2. Rechtermuisknop op titelbalk > **Edit > Select All**, daarna `Enter`.
3. Gebruik `Ctrl+Shift+C` (Windows Terminal).
4. Schrijf output direct naar bestand en kopieer dat bestand:

```powershell
cd C:\temp\tacx
.\diagnose_tacx_visibility.ps1 *> C:\temp\tacx\diag_output.txt
notepad C:\temp\tacx\diag_output.txt
```

5. Of naar klembord met `clip`:

```powershell
.\diagnose_tacx_visibility.ps1 | Out-String | Set-Clipboard
```


## Patch originele ANT_LibUsb.inf met Tacx GUID (indien ontbreekt)

Als `ANT_LibUsb.inf` de GUID `{3c5e1462-5695-4e18-876b-f3f3d08aaf18}` niet bevat, patch hem dan eerst:

```powershell
Set-ExecutionPolicy -Scope Process Bypass -Force
cd C:\temp\tacx
.\patch_ant_libusb_inf.ps1 -InfPath C:\temp\tacx\ant_usb2_drivers\ANT_LibUsb.inf
pnputil /add-driver C:\temp\tacx\ant_usb2_drivers\ANT_LibUsb.inf /install
```

Controle:

```powershell
reg query "HKLM\System\CurrentControlSet\Control\DeviceClasses\{3c5e1462-5695-4e18-876b-f3f3d08aaf18}" /s
```


> Note: some packages use `[LIBUSB_WIN32_DEV.NT]` instead of `[ANT_LibUsb.NT]`; the patch script now supports both patterns.
