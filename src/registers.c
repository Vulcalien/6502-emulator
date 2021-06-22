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
#include "private/registers.h"

u16 reg_pc = 0;
u8  reg_s  = 0;
u8  reg_a  = 0;
u8  reg_x  = 0;
u8  reg_y  = 0;

union processor_flags reg_flags = {0};

void cpu_registers_init(void) {
    reg_flags.b = 1;
    reg_flags.u = 1;
}
