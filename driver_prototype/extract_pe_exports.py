#!/usr/bin/env python3
from pathlib import Path
import struct
import sys


def rva_to_off(rva, sections):
    for va, vsz, raw_ptr, raw_sz in sections:
        size = max(vsz, raw_sz)
        if va <= rva < va + size:
            return raw_ptr + (rva - va)
    return None


def read_u16(b, o):
    return struct.unpack_from('<H', b, o)[0]


def read_u32(b, o):
    return struct.unpack_from('<I', b, o)[0]


def parse_exports(pe: bytes):
    if pe[0:2] != b'MZ':
        raise ValueError('Not a PE file (missing MZ).')
    pe_off = read_u32(pe, 0x3C)
    if pe[pe_off:pe_off+4] != b'PE\0\0':
        raise ValueError('Invalid PE signature.')

    file_header = pe_off + 4
    nsec = read_u16(pe, file_header + 2)
    opt_size = read_u16(pe, file_header + 16)
    opt = file_header + 20

    magic = read_u16(pe, opt)
    if magic == 0x10B:
        dd_base = opt + 96
    elif magic == 0x20B:
        dd_base = opt + 112
    else:
        raise ValueError('Unsupported optional header magic.')

    export_rva = read_u32(pe, dd_base)
    export_size = read_u32(pe, dd_base + 4)
    if export_rva == 0:
        return []

    sec_off = opt + opt_size
    sections = []
    for i in range(nsec):
        s = sec_off + i * 40
        va = read_u32(pe, s + 12)
        vsz = read_u32(pe, s + 8)
        raw_sz = read_u32(pe, s + 16)
        raw_ptr = read_u32(pe, s + 20)
        sections.append((va, vsz, raw_ptr, raw_sz))

    exp_off = rva_to_off(export_rva, sections)
    if exp_off is None:
        return []

    number_of_names = read_u32(pe, exp_off + 24)
    address_of_names = read_u32(pe, exp_off + 32)
    names_off = rva_to_off(address_of_names, sections)
    if names_off is None:
        return []

    out = []
    for i in range(number_of_names):
        name_rva = read_u32(pe, names_off + i * 4)
        noff = rva_to_off(name_rva, sections)
        if noff is None:
            continue
        end = pe.find(b'\x00', noff)
        if end == -1:
            continue
        out.append(pe[noff:end].decode('ascii', errors='ignore'))
    return out


def main():
    if len(sys.argv) != 3:
        print('Usage: extract_pe_exports.py <dll_path> <out_txt>')
        return 2
    dll = Path(sys.argv[1])
    out = Path(sys.argv[2])
    data = dll.read_bytes()
    names = parse_exports(data)
    if not names:
        print('[ERROR] No export names found.')
        return 1
    out.write_text('\n'.join(names) + '\n')
    print(f'[OK] Exports: {len(names)}')
    print(f'[OK] Wrote: {out}')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
