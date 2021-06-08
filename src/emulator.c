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
#include "emulator.h"

#include "registers.h"
#include "execute.h"

u8 *memory;

int main(int argc, const char *argv[]) {
    execute_init();

    memory = calloc(MEMORY_SIZE, sizeof(u8));

    while(true) {
        execute(fetch_byte());

        for(u16 i = 0; i < 16; i++) {
            for(u16 j = 0; j < 16; j++) {
                printf("%3d ", memory[i + j  * 16]);
            }
            putchar('\n');
        }
        getchar();
    }
}

u8 fetch_byte(void) {
    u8 result = memory[reg_pc];
    reg_pc++;
    return result;
}

u8 read_byte_absolute(u16 address) {
    return memory[address];
}
