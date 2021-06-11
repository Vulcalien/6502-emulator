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
#ifndef VULC_6502_EMULATOR_MEMORY_IO_P
#define VULC_6502_EMULATOR_MEMORY_IO_P

#include "private/emulator.h"

#define READ_B(x)  u8  x(void)
#define READ_W(x)  u16 x(void)
#define WRITE_B(x) void x(u8 byte)

extern u16  mem_get_addr(void);

extern u8   mem_read_byte(void);
extern u16  mem_read_word(void);
extern void mem_write_byte(u8 byte);

extern u8   stack_pull_byte(void);
extern u16  stack_pull_word(void);
extern void stack_push_byte(u8 byte);
extern void stack_push_word(u16 word);

extern void mem_set_addressing(u16 (*addr)(void));
extern void mem_clear_addr_cache(void);

#endif // VULC_6502_EMULATOR_MEMORY_IO_P
