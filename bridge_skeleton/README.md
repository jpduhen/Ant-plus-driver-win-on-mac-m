# Bridge skeleton – volgende stap

Doel: een vervangende `ANT_WrappedLib.dll` maken die dezelfde exports aanbiedt als de originele DLL,
maar intern logt en later doorzet naar WinUSB/libusb implementatie.

## Stap 1: exports inventariseren op de werkende/legacy setup

Optie A (met Visual Studio tools / dumpbin):

```bat
cd /d "C:\Program Files (x86)\Tacx\TacxTrainersoftware4"
dumpbin /exports ANT_WrappedLib.dll > C:\temp\tacx\ant_wrapped_exports.txt
```

Optie B (zonder dumpbin, pure Python):

```powershell
python C:\temp\tacx\driver_prototype\extract_pe_exports.py "C:\Program Files (x86)\Tacx\TacxTrainersoftware4\ANT_WrappedLib.dll" C:\temp\tacx\ant_wrapped_exports.txt
```

## Stap 2: skeleton generatie

Gebruik `driver_prototype/generate_bridge_skeleton.py`:

```bash
python3 driver_prototype/generate_bridge_skeleton.py C:\temp\tacx\ant_wrapped_exports.txt bridge_skeleton
```

Dit maakt:
- `bridge_skeleton/ant_bridge.def`
- `bridge_skeleton/ant_bridge_stub.c`

## Stap 3: gedrag

De gegenereerde stubs retourneren standaard foutcodes en schrijven logging via `OutputDebugStringA`.
Daarna kunnen per functie echte implementaties toegevoegd worden.
