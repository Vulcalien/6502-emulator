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
#ifndef VULC_6502_EMULATOR_MEMORY_IO
#define VULC_6502_EMULATOR_MEMORY_IO

#include "emulator.h"

#define READ_B(x)  u8  x(void)
#define READ_W(x)  u16 x(void)
#define WRITE_B(x) void x(u8 byte)

// function variables
extern u8   (*mem_read_byte) (void);
extern u16  (*mem_read_word) (void);
extern void (*mem_write_byte)(u8 byte);

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
extern READ_B(read_byte_acc);
extern WRITE_B(write_byte_acc);

// IMM - immediate
extern READ_B(read_byte_imm);

// TODO unsure about the next stuff
// should they all be implemented ???

// ZPG - zero page
extern READ_B(read_byte_zpg);
extern READ_W(read_word_zpg);
extern WRITE_B(write_byte_zpg);

// ZPX - zero page X
extern READ_B(read_byte_zpx);
extern READ_W(read_word_zpx);
extern WRITE_B(write_byte_zpx);

// ZPY - zero page Y
extern READ_B(read_byte_zpy);
extern READ_W(read_word_zpy);
extern WRITE_B(write_byte_zpy);

// REL - relative
extern READ_B(read_byte_rel);
extern READ_W(read_word_rel);
extern WRITE_B(write_byte_rel);

// ABS - absolute
extern READ_B(read_byte_abs);
extern READ_W(read_word_abs);
extern WRITE_B(write_byte_abs);

// ABX - absolute X
extern READ_B(read_byte_abx);
extern READ_W(read_word_abx);
extern WRITE_B(write_byte_abx);

// ABY - absolute Y
extern READ_B(read_byte_aby);
extern READ_W(read_word_aby);
extern WRITE_B(write_byte_aby);

// IND - indirect
extern READ_B(read_byte_ind);
extern READ_W(read_word_ind);
extern WRITE_B(write_byte_ind);

// INX - indirect X
extern READ_B(read_byte_inx);
extern READ_W(read_word_inx);
extern WRITE_B(write_byte_inx);

// INY - indirect Y
extern READ_B(read_byte_iny);
extern READ_W(read_word_iny);
extern WRITE_B(write_byte_iny);

#endif // VULC_6502_EMULATOR_MEMORY_IO
