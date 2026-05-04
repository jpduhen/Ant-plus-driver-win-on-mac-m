#!/usr/bin/env python3
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parent.parent
DRIVER_DIR = ROOT / "ant_usb2_drivers"
TARGET = ("0FCF", "1008")

hwid_re = re.compile(r"USB\\VID_([0-9A-Fa-f]{4})&PID_([0-9A-Fa-f]{4})(?:&REV_([0-9A-Fa-f]{4}))?")


def main() -> int:
    if not DRIVER_DIR.exists():
        print(f"[ERROR] Map ontbreekt: {DRIVER_DIR}")
        print("Voeg de originele driverbestanden toe onder ant_usb2_drivers/{amd64,x86,ia64}.")
        return 1

    inf_files = sorted(DRIVER_DIR.rglob("*.inf"))
    if not inf_files:
        print("[ERROR] Geen .inf bestanden gevonden in ant_usb2_drivers.")
        return 1

    any_match = False
    print(f"[INFO] INF-bestanden gevonden: {len(inf_files)}")
    for inf in inf_files:
        text = inf.read_text(errors="ignore")
        matches = hwid_re.findall(text)
        if not matches:
            continue

        rel = inf.relative_to(ROOT)
        print(f"\n== {rel} ==")
        seen = set()
        for vid, pid, rev in matches:
            key = (vid.upper(), pid.upper(), (rev or "").upper())
            if key in seen:
                continue
            seen.add(key)
            marker = "<-- MATCH" if (vid.upper(), pid.upper()) == TARGET else ""
            hwid = f"USB\\VID_{vid.upper()}&PID_{pid.upper()}"
            if rev:
                hwid += f"&REV_{rev.upper()}"
            print(f"  {hwid} {marker}".rstrip())
            if marker:
                any_match = True

    print("\n[RESULT]")
    if any_match:
        print("Doel hardware-ID (VID_0FCF/PID_1008) is gevonden in minstens één INF.")
        return 0
    print("Doel hardware-ID niet gevonden. Waarschijnlijk verkeerde driverpakket of ontbrekende INF.")
    return 2


if __name__ == "__main__":
    raise SystemExit(main())
