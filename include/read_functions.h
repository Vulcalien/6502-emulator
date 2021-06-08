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

// implicit
extern read_function R_IMP;
// accumulator
extern read_function R_ACC;
// immediate
extern read_function R_IMM;
// zero page
extern read_function R_ZPG;
// zero page X
extern read_function R_ZPX;
// zero page Y
extern read_function R_ZPY;
// relative
extern read_function R_REL;
// absolute
extern read_function R_ABS;
// absolute X
extern read_function R_ABX;
// absolute Y
extern read_function R_ABY;
// indirect
extern read_function R_IND;
// indirect X
extern read_function R_INX;
// indirect Y
extern read_function R_INY;

#endif // VULC_6502_EMULATOR_READ_FUNCTIONS
