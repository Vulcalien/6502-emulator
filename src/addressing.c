/* Copyright 2021 Vulcalien
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
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
#include "addressing.h"

#include <stdio.h>

#include "registers.h"

u16 A_IMP(void) {
    fputs("Error: IMP function called.\n", stderr);
    return 0;
}

u16 A_ACC(void) {
    fputs("Error: ACC function called.\n", stderr);
    return 0;
}

u16 A_IMM(void) {
    fputs("Error: IMM function called.\n", stderr);
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
    fputs("Error: REL function called.\n", stderr);
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
    // TODO - IND
    return 0;
}

u16 A_INX(void) {
    // TODO - INX
    return 0;
}

u16 A_INY(void) {
    // TODO - INY
    return 0;
}
