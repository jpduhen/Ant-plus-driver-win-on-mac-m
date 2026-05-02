# Installatieprototype: Tacx ANT+ via WinUSB op Windows 11 ARM64

Dit is een **eerste technische proef** om te testen of de Tacx T2018 dongle in jouw VM aanspreekbaar wordt zonder de oude kernel-driver.

## Voorwaarden

- Parallels USB passthrough staat op **Connect to Windows** voor de dongle.
- Device zichtbaar als `USB\VID_0FCF&PID_1008` in Device Manager.
- Je draait deze stappen in een **Administrator PowerShell** of **Administrator Command Prompt**.

## Bestanden kopiëren

Plaats deze bestanden op Windows, bijvoorbeeld in `C:\temp\tacx\`:

- `tacx_winusb_arm64.inf`
- `tacx_winusb_arm64_compat.inf`
- `manage_tacx_driver.ps1`

## Snelste route: script gebruiken

```powershell
Set-ExecutionPolicy -Scope Process Bypass
cd C:\temp\tacx
.\manage_tacx_driver.ps1 -Action install-a
```

Als Tacx software nog niets ziet:

```powershell
.\manage_tacx_driver.ps1 -Action install-b
```

Status bekijken:

```powershell
.\manage_tacx_driver.ps1 -Action status
```

Prototype drivers opruimen:

```powershell
.\manage_tacx_driver.ps1 -Action remove
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

Controle:

```bat
pnputil /enum-devices /connected
pnputil /enum-drivers
```

## Als installatie geblokkeerd wordt

Deze INF's zijn niet gesigneerd. Voor een proof-of-concept kun je testsigning gebruiken. In productie moet de driver officieel gesigneerd worden.
