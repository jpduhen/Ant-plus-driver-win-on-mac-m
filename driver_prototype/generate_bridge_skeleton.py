#!/usr/bin/env python3
from pathlib import Path
import re
import sys

EXPORT_RE = re.compile(r"^\s*\d+\s+[0-9A-F]+\s+[0-9A-F]+\s+([A-Za-z_][A-Za-z0-9_@?$]*)\s*$")


def parse_exports(text: str):
    exports = []
    for raw in text.splitlines():
        line = raw.strip()
        if not line:
            continue

        # dumpbin format
        m = EXPORT_RE.match(line)
        if m:
            name = m.group(1)
            if name not in exports:
                exports.append(name)
            continue

        # plain one-name-per-line format (from extract_pe_exports.py)
        if re.match(r"^[A-Za-z_][A-Za-z0-9_@?$]*$", line):
            if line not in exports:
                exports.append(line)

    return exports


def main() -> int:
    if len(sys.argv) != 3:
        print("Usage: generate_bridge_skeleton.py <ant_wrapped_exports.txt> <out_dir>")
        return 2

    src = Path(sys.argv[1])
    out = Path(sys.argv[2])
    if not src.exists():
        print(f"[ERROR] Missing export file: {src}")
        return 1

    text = src.read_text(errors="ignore")
    exports = parse_exports(text)
    if not exports:
        print("[ERROR] No exports found in input file.")
        return 1

    out.mkdir(parents=True, exist_ok=True)

    def_path = out / "ant_bridge.def"
    c_path = out / "ant_bridge_stub.c"

    def_lines = ["LIBRARY ANT_WrappedLib", "EXPORTS"]
    def_lines += [f"  {name}" for name in exports]
    def_path.write_text("\n".join(def_lines) + "\n")

    c_lines = [
        "#include <windows.h>",
        "",
        "static void log_call(const char* fn) {",
        "    OutputDebugStringA(fn);",
        "    OutputDebugStringA(\"\\n\");",
        "}",
        "",
    ]
    for name in exports:
        c_lines += [
            f"__declspec(dllexport) DWORD {name}(void) {{",
            f"    log_call(\"{name}\");",
            "    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);",
            "    return 0;",
            "}",
            "",
        ]
    c_path.write_text("\n".join(c_lines))

    print(f"[OK] Exports parsed: {len(exports)}")
    print(f"[OK] Wrote: {def_path}")
    print(f"[OK] Wrote: {c_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
