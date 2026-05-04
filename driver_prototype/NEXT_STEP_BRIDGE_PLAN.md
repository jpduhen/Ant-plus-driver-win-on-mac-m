# Waarom Tacx software de dongle nog niet ziet (en wat nu)

## Conclusie uit diagnose

De driverinstallatie is **succesvol**:

- Device status: `CM_PROB_NONE` / `Started`.
- Service: `WINUSB`.
- INF: `oem11.inf` (`tacx_winusb_arm64_compat.inf`).
- SetupAPI eindigt met `Exit status: SUCCESS`.

Dus: het probleem is niet meer PnP/INF/signing.

## Waarschijnlijke oorzaak

Tacx Trainer Software 4.23.01 verwacht zeer waarschijnlijk niet "zomaar een USB device", maar een **specifieke ANT runtime/API** (bijv. vendor DLL/driver stack met vaste function calls).

Met alleen WinUSB is het device zichtbaar in Windows, maar de app mist de verwachte softwarelaag.

## Nieuwe oplossing: API bridge i.p.v. extra INF-tweaks

1. Bepaal welke DLL/API Tacx gebruikt.
2. Maak een compatibele bridge-DLL die dezelfde exports aanbiedt.
3. Laat bridge intern met WinUSB praten naar `VID_0FCF/PID_1008`.

## Stap 1 — vind ontbrekende afhankelijkheden

In Windows VM:

```powershell
# Vanuit map met Tacx executable
Get-Item .\TacxTrainerSoftware.exe
```

Gebruik daarna bij voorkeur `Dependencies.exe` (of `dumpbin /imports`) en noteer:

- welke ANT-gerelateerde DLL's worden geladen;
- welke functies uit die DLL's worden aangeroepen.

## Stap 2 — runtime logging

Controleer tijdens opstarten van Tacx software:

- Process Monitor (filter op Process Name + Result = NAME NOT FOUND)
- specifiek op missende `.dll` en registry keys rond ANT/Tacx USB.

## Stap 3 — bridge proof-of-concept

Bridge-DLL doel:

- Exporteert dezelfde symbolen als de verwachte ANT DLL.
- Voor minimale PoC hoeven eerst alleen init/open/read/write/close paden te werken.
- Intern gebruikt bridge WinUSB (`WinUsb_Initialize`, `WinUsb_ReadPipe`, `WinUsb_WritePipe`).

## Verwacht resultaat

Als Tacx de bridge-DLL accepteert, ziet de software de dongle zonder custom kernel-driver.


## Nieuwe bevinding (Windows 11 ARM64, 2026-05-04)

Bij staging van de volledige `TacxDrivers` bundle wordt de Jungo stack (`windrvr1230.inf`) wel aan de DriverStore toegevoegd, maar het ANT device eindigt in `Status: Error` na re-enumeratie.

Dat wijst sterk op architectuurmismatch van de legacy Jungo kernel component (x86/x64) op ARM64.

Gevolg: pure INF/PnP tweaks blijven waarschijnlijk onvoldoende; bridge-aanpak (user-space shim) is de meest realistische route.
