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
#ifndef VULC_6502_EMULATOR_REGISTERS_P
#define VULC_6502_EMULATOR_REGISTERS_P

#include "private/emulator.h"

union processor_flags {
    struct {
        u8 c:1; // C - carry flag
        u8 z:1; // Z - zero flag
        u8 i:1; // I - interrupt disable
        u8 d:1; // D - decimal mode
        u8 b:1; // B - break flag
        u8 u:1; // U - unused
        u8 v:1; // V - overflow flag
        u8 n:1; // N - negative flag
    };
    u8 as_byte;
};

extern u16 reg_pc; // PC - program counter
extern u8  reg_s;  //  S - stack pointer
extern u8  reg_a;  //  A - acculumator
extern u8  reg_x;  //  X - X index
extern u8  reg_y;  //  Y - Y index

// processor flags
extern union processor_flags reg_flags;

extern void cpu_registers_init(void);

#endif // VULC_6502_EMULATOR_REGISTERS_P
