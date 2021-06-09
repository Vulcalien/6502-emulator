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
#ifndef VULC_6502_EMULATOR_API
#define VULC_6502_EMULATOR_API

#include "vulcalien/vulcalien.h"

extern u8 (*cpu_read_byte)(u16 addr);
extern void (*cpu_write_byte)(u16 addr, u8 val);

// initialize library internal variables
extern void cpu_init(void);

// this is not an actual clock, but a whole instruction
extern void cpu_clock(void);

#endif // VULC_6502_EMULATOR_API
