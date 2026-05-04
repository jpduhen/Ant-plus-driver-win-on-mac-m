#!/usr/bin/env python3
from pathlib import Path
import re

default_path = Path('driver_prototype/diag_output.txt')
if default_path.exists():
    p = default_path
else:
    candidates = list(Path('.').rglob('diag_output.txt'))
    if candidates:
        p = candidates[0]
        print(f'[INFO] Gebruik gevonden bestand: {p}')
    else:
        print('[ERROR] diag_output.txt niet gevonden in deze checkout.')
        print('Plaats het bestand lokaal (bijv. driver_prototype/diag_output.txt) of plak de inhoud in chat.')
        raise SystemExit(1)

text = p.read_text(errors='ignore')

print('[INFO] Analyse diag_output.txt')

checks = {
    'winusb_service': r'WinUSB service status',
    'service_name': r'DEVPKEY_Device_Service',
    'class_guid': r'DEVPKEY_Device_ClassGuid',
    'tacx_driver_pkg': r'Tacx|ANT\+|WinUSB',
}

for k, pat in checks.items():
    print(f'- {k}:', 'gevonden' if re.search(pat, text, re.I) else 'niet gevonden')

svc = re.findall(r'DEVPKEY_Device_Service\s+(.+)', text)
if svc:
    print('\n[DETAIL] Mogelijke services:')
    for s in sorted(set(x.strip() for x in svc)):
        print('  -', s)

if re.search(r'ConfigManagerErrorCode\s*:\s*0', text):
    print('\n[RESULT] Device lijkt correct geïnstalleerd (CM error 0).')
else:
    print('\n[RESULT] Device heeft mogelijk nog install-/driverfout (CM error != 0).')

if re.search(r'WinUSB', text, re.I):
    print('[HINT] Driver draait waarschijnlijk op WinUSB. Als Tacx app niets ziet, verwacht de app vermoedelijk een andere API/service.')
