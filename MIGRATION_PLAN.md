# Tacx ANT+ dongle op Windows 11 ARM (Parallels op Apple Silicon)

## Huidige situatie

- Host: Mac mini M4 (Apple Silicon).
- VM: Parallels 26 met Windows 11 ARM64.
- Doel-applicatie: Tacx Trainer Software 4.23.01.
- Dongle: Tacx T2018 (AD162), USB ID: `VID_0FCF` / `PID_1008` / `REV_0100`.
- Probleem: dongle wordt niet geïnstalleerd omdat de oude Windows-driver niet matcht met huidige ARM64/VM situatie.

## Belangrijk om te weten

- `x86`, `amd64` en `ia64` drivers zijn **geen ARM64** drivers.
- `ia64` (Itanium) is historisch en niet bruikbaar voor Windows 11 ARM.
- Op Windows 11 ARM kunnen x86/x64 user-space binaries vaak geëmuleerd worden, maar kernel-drivers (`.sys`) niet zomaar.

## Benodigde bestanden (in repository toevoegen)

Plaats de driverbestanden onder `ant_usb2_drivers/` met deze structuur:

```text
ant_usb2_drivers/
  amd64/
  x86/
  ia64/
```

Per map graag alle originele bestanden:

- `.inf`
- `.sys`
- `.cat`
- eventuele `.dll`
- setup/installers (`setup.exe`, `.msi`, `dpinst*`)

## Eerste analyse-stappen (zodra bestanden aanwezig zijn)

1. Hardware IDs uit `.inf` vergelijken met:
   - `USB\\VID_0FCF&PID_1008&REV_0100`
2. Bepalen of het pakket een custom kernel-driver nodig heeft of WinUSB/libusb kan gebruiken.
3. Controleren of INF kan worden aangepast voor ARM64 (en wat certificering-signing impact is).
4. Bepalen van werkpad:
   - **A:** native ARM64 driver (moeilijk/waarschijnlijk broncode nodig), of
   - **B:** user-space bridge (realistischer), of
   - **C:** USB passthrough + alternatieve bestaande driver stack.

## Praktisch testplan in Parallels

1. Verifieer dat dongle direct aan Windows VM gekoppeld is (niet aan macOS host).
2. Controleer in Device Manager of onbekend USB-device zichtbaar is met bovenstaande VID/PID.
3. Maak een export van huidige PnP status:
   - `pnputil /enum-devices /connected`
   - `pnputil /enum-drivers`
4. Na INF-prototype: handmatige installatie met `pnputil /add-driver <inf> /install`.
5. Daarna valideren of Tacx Trainer Software 4.23.01 de dongle detecteert.

## Volgende stap

Voeg de volledige inhoud van `ant_usb2_drivers` toe in deze repo. Daarna kunnen we direct starten met een concrete INF/driver-analyse en een uitvoerbaar migratiepad kiezen.
