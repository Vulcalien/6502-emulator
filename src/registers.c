/* Copyright 2021 Vulcalien
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include "private/registers.h"

u16 reg_pc = 0;
u8  reg_s  = 0;
u8  reg_a  = 0;
u8  reg_x  = 0;
u8  reg_y  = 0;

union processor_flags reg_flags = {0};

void registers_init(void) {
    reg_flags.b = 1;
    reg_flags.u = 1;
}
