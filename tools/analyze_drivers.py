#!/usr/bin/env python3
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parent.parent
DRIVER_DIR_CANDIDATES = [
    ROOT / "ant_usb2_drivers",
    ROOT / "TacxDrivers",
]
TARGET = ("0FCF", "1008")

hwid_re = re.compile(r"USB\\VID_([0-9A-Fa-f]{4})&PID_([0-9A-Fa-f]{4})(?:&REV_([0-9A-Fa-f]{4}))?")
provider_re = re.compile(r"^\s*Provider\s*=\s*(.+)$", re.IGNORECASE | re.MULTILINE)
class_re = re.compile(r"^\s*Class\s*=\s*(.+)$", re.IGNORECASE | re.MULTILINE)


def main() -> int:
    existing = [p for p in DRIVER_DIR_CANDIDATES if p.exists()]
    if not existing:
        print("[ERROR] Geen drivermappen gevonden.")
        print("Voeg driverbestanden toe onder ant_usb2_drivers/ of TacxDrivers/.")
        return 1

    inf_files = []
    for d in existing:
        inf_files.extend(sorted(d.rglob("*.inf")))

    if not inf_files:
        print("[ERROR] Geen .inf bestanden gevonden in gevonden drivermappen.")
        return 1

    any_match = False
    print(f"[INFO] INF-bestanden gevonden: {len(inf_files)}")
    print("[INFO] Gescande mappen:")
    for d in existing:
        print(f"  - {d}")

    for inf in inf_files:
        text = inf.read_text(errors="ignore")
        matches = hwid_re.findall(text)
        if not matches:
            continue

        rel = inf.relative_to(ROOT)
        provider = (provider_re.search(text).group(1).strip() if provider_re.search(text) else "?")
        klass = (class_re.search(text).group(1).strip() if class_re.search(text) else "?")
        print(f"\n== {rel} ==")
        print(f"  Provider: {provider}")
        print(f"  Class   : {klass}")
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
        print("Tip: vergelijk Providers (bijv. Dynastream/Jungo/Tacx) voor juiste runtime-stack.")
        return 0
    print("Doel hardware-ID niet gevonden. Waarschijnlijk verkeerde driverpakket of ontbrekende INF.")
    return 2


if __name__ == "__main__":
    raise SystemExit(main())
