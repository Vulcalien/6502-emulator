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
#ifndef VULC_6502_EMULATOR_READ_FUNCTIONS
#define VULC_6502_EMULATOR_READ_FUNCTIONS

#include "emulator.h"

typedef u8 (*read_function)(void);

extern read_function R_IMP; // implicit
extern read_function R_ACC; // accumulator
extern read_function R_IMM; // immediate
extern read_function R_ZPG; // zero page
extern read_function R_ZPX; // zero page X
extern read_function R_ZPY; // zero page Y
extern read_function R_REL; // relative
extern read_function R_ABS; // absolute
extern read_function R_ABX; // absolute X
extern read_function R_ABY; // absolute Y
extern read_function R_IND; // indirect
extern read_function R_INX; // indirect X
extern read_function R_INY; // indirect Y

#endif // VULC_6502_EMULATOR_READ_FUNCTIONS
