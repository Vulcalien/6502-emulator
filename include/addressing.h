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
#ifndef VULC_6502_EMULATOR_ADDRESSING
#define VULC_6502_EMULATOR_ADDRESSING

#include "emulator.h"

u16 A_IMP(void); // implicit
u16 A_ACC(void); // accumulator
u16 A_IMM(void); // immediate
u16 A_ZPG(void); // zero page
u16 A_ZPX(void); // zero page X
u16 A_ZPY(void); // zero page Y
u16 A_REL(void); // relative
u16 A_ABS(void); // absolute
u16 A_ABX(void); // absolute X
u16 A_ABY(void); // absolute Y
u16 A_IND(void); // indirect
u16 A_INX(void); // indirect X
u16 A_INY(void); // indirect Y

#endif // VULC_6502_EMULATOR_ADDRESSING
