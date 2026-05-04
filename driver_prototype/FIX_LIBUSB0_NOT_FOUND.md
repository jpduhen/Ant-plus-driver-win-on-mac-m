# Fix voor `libusb0.dll` ontbreekt (uit ProcMon logs)

Uit jouw logs blijkt:

- `TrainerSoftware.exe` zoekt expliciet naar `libusb0.dll`.
- Op meerdere locaties krijg je `NAME NOT FOUND`.

Dat verklaart waarom de app de dongle niet ziet, ook al is WinUSB-driver OK.

## Oplossing


## Welke DLL moet je kiezen?

Gebruik voor Tacx Trainer Software 4.23.01 (x86 app) **de x86 variant**:

1. `libusb0_x86.dll` (beste keuze)
2. anders `libusb0.dll` uit de x86 drivermap
3. **niet** de ARM64 `libusb0.dll` voor deze app

De app draait onder `Program Files (x86)` en zoekt in `SysWOW64`, dus verwacht 32-bit DLL's.

1. Zorg dat je een **32-bit** `libusb0.dll` hebt (x86), bijvoorbeeld uit je oude Tacx/ANT installatie.
2. Plaats die tijdelijk in `C:\temp\tacx\runtime\libusb0.dll`.
3. Run (Admin PowerShell):

```powershell
Set-ExecutionPolicy -Scope Process Bypass -Force
cd C:\temp\tacx
.\fix_libusb_runtime.ps1 -TacxDir "C:\Program Files (x86)\Tacx\TacxTrainersoftware4" -SourceRoot "C:\temp\tacx"
```

Dit kopieert `libusb0.dll` naar:

- `C:\Program Files (x86)\Tacx\TacxTrainersoftware4\libusb0.dll`
- `C:\Windows\SysWOW64\libusb0.dll`

## Daarna testen

1. Sluit Tacx volledig.
2. Start Tacx opnieuw.
3. Als nog geen detectie: nieuwe ProcMon capture maken (zelfde filter) en check of `libusb0.dll` nu `SUCCESS` is.
