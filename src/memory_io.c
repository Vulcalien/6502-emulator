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
#include "memory_io.h"

#include "registers.h"

u8  (*mem_read_byte)(void) = NULL;
u16 (*mem_read_word)(void) = NULL;

void (*mem_write_byte)(u8 byte) = NULL;

/* Addressing mode:
 * imp = implicit
 * acc = accumulator
 * imm = immediate
 * zpg = zero page
 * zpx = zero page X
 * zpy = zero page Y
 * rel = relative
 * abs = absolute
 * abx = absolute X
 * aby = absolute Y
 * ind = indirect
 * inx = indirect X
 * iny = indirect Y
 */

// ACC - accumulator
READ_B(read_byte_acc) {
    return reg_a;
}
WRITE_B(write_byte_acc) {
    reg_a = byte;
}

// IMM - immediate
READ_B(read_byte_imm) {
    return fetch_byte();
}
