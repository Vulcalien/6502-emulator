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
#ifndef VULC_6502_EMULATOR_ADDRESS_MODES
#define VULC_6502_EMULATOR_ADDRESS_MODES

#include "emulator.h"

typedef u8 (*addr_function)(void);

extern addr_function A_IMP; // implicit
extern addr_function A_ACC; // accumulator
extern addr_function A_IMM; // immediate
extern addr_function A_ZPG; // zero page
extern addr_function A_ZPX; // zero page X
extern addr_function A_ZPY; // zero page Y
extern addr_function A_REL; // relative
extern addr_function A_ABS; // absolute
extern addr_function A_ABX; // absolute X
extern addr_function A_ABY; // absolute Y
extern addr_function A_IND; // indirect
extern addr_function A_INX; // indirect X
extern addr_function A_INY; // indirect Y

#endif // VULC_6502_EMULATOR_ADDRESS_MODES
