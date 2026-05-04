# Ant-plus-driver-win-on-mac-m

Project om een Tacx ANT+ USB-dongle werkend te krijgen in Windows 11 ARM64 (Parallels op Apple Silicon), zodat Tacx Trainer Software 4.23.01 gebruikt kan worden.

## Huidige status

- We hebben een **eerste ARM64-proof-of-concept** gemaakt met een WinUSB-gebaseerde INF:
  - `driver_prototype/tacx_winusb_arm64.inf`
  - `driver_prototype/tacx_winusb_arm64_compat.inf`
  - `driver_prototype/INSTALL_WINDOWS11_ARM64.md`
  - `driver_prototype/manage_tacx_driver.ps1`
  - `driver_prototype/COMMANDS_WINDOWS11_ARM64.md`
  - `driver_prototype/SIGN_AND_INSTALL_WINDOWS11_ARM64.md`
  - `driver_prototype/autosign_and_install.ps1`

## Driver-analyse

1. Zet de originele drivers in `ant_usb2_drivers/{amd64,x86,ia64}`.
2. Draai de snelle analyse:

```bash
python3 tools/analyze_drivers.py
```

Deze checkt of de INF-bestanden de Tacx dongle hardware-ID bevatten (`USB\\VID_0FCF&PID_1008`).

Zie `MIGRATION_PLAN.md` voor de technische aanpak.
