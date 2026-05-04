# Exacte commands voor stap 1 en 2 (Tacx app detectie)

Doel: in 5 minuten bepalen welke DLL/API Tacx verwacht en wat er mist tijdens runtime.

## Stap 1 — imports van Tacx executable uitlezen

### 1A) Met dumpbin (Visual Studio Developer Command Prompt)

```bat
cd /d "C:\Program Files (x86)\Tacx\TacxTrainersoftware4"
dumpbin /imports TacxTrainerSoftware.exe > C:\temp\tacx\tacx_imports.txt
findstr /i "ant tacx usb dsi" C:\temp\tacx\tacx_imports.txt
```

### 1B) Alternatief met Dependencies GUI

```powershell
# Start Dependencies.exe handmatig en open TacxTrainerSoftware.exe
# Exporteer lijst met imports naar C:\temp\tacx\dependencies_export.txt
```

## Stap 2 — runtime missers loggen met Process Monitor

1. Start ProcMon als Administrator.
2. Druk `Ctrl+L` en zet filters:
   - `Process Name` `is` `TacxTrainerSoftware.exe` `Include`
   - `Result` `is` `NAME NOT FOUND` `Include`
3. Clear huidige events (Ctrl+X).
4. Start Tacx software en wacht tot "dongle niet gevonden".
5. Stop capture (Ctrl+E).
6. Save:
   - `File -> Save -> Events displayed using current filter`
   - naar: `C:\temp\tacx\procmon_tacx_missing.csv`

## Snelle extractie van interessante regels

```powershell
Import-Csv C:\temp\tacx\procmon_tacx_missing.csv |
  Where-Object { $_.Path -match '\\.(dll|sys)$|ANT|Tacx|0FCF|1008' } |
  Select-Object TimeofDay, ProcessName, Operation, Path, Result |
  Format-Table -AutoSize
```

## Deel daarna deze 3 bestanden

- `C:\temp\tacx\tacx_imports.txt`
- `C:\temp\tacx\dependencies_export.txt` (als je Dependencies gebruikt)
- `C:\temp\tacx\procmon_tacx_missing.csv`
