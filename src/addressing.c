/* Copyright 2021 Vulcalien
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
#include "private/addressing.h"

#include <stdio.h>

#include "private/registers.h"

u16 A_IMP(void) {
    fputs("6502 Error: A_IMP function called.\n", stderr);
    return 0;
}

u16 A_ACC(void) {
    fputs("6502 Error: A_ACC function called.\n", stderr);
    return 0;
}

u16 A_IMM(void) {
    fputs("6502 Error: A_IMM function called.\n", stderr);
    return 0;
}

u16 A_ZPG(void) {
    return fetch_byte();
}

u16 A_ZPX(void) {
    u8 addr = fetch_byte() + reg_x;
    return addr;
}

u16 A_ZPY(void) {
    u8 addr = fetch_byte() + reg_y;
    return addr;
}

u16 A_REL(void) {
    fputs("6502 Error: A_REL function called.\n", stderr);
    return 0;
}

u16 A_ABS(void) {
    return BYTES_TO_WORD(fetch_byte(), fetch_byte());
}

u16 A_ABX(void) {
    return BYTES_TO_WORD(fetch_byte(), fetch_byte()) + reg_x;
}

u16 A_ABY(void) {
    return BYTES_TO_WORD(fetch_byte(), fetch_byte()) + reg_y;
}

u16 A_IND(void) {
    u16 ptr_addr = BYTES_TO_WORD(fetch_byte(), fetch_byte());
    return BYTES_TO_WORD(
        cpu_read_byte(ptr_addr),
        cpu_read_byte((ptr_addr & 0xff00) | ((ptr_addr + 1) & 0xff))
    );
}

u16 A_INX(void) {
    u8 ptr_addr = fetch_byte() + reg_x;
    return BYTES_TO_WORD(cpu_read_byte(ptr_addr), cpu_read_byte(ptr_addr + 1));
}

u16 A_INY(void) {
    u8 ptr_addr = fetch_byte();
    return BYTES_TO_WORD(cpu_read_byte(ptr_addr), cpu_read_byte(ptr_addr + 1))
           + reg_y;
}
