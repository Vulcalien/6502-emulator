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
#ifndef VULC_6502_EMULATOR_CORE_P
#define VULC_6502_EMULATOR_CORE_P

#include <stdlib.h>

#include "vulcalien/vulcalien.h"

#define MEMORY_SIZE (0xffff + 1)

#define BYTES_TO_WORD(lo, hi) (lo | (hi << 8))

extern u8 *memory;

/* Fetch one byte from memory and increment the program counter.
 * Costs one CPU cycle. */
extern u8 fetch_byte(void);

#endif // VULC_6502_EMULATOR_CORE_P
