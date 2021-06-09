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
#include "private/emulator.h"

#include "private/registers.h"
#include "private/execute.h"

u8 (*read_byte)(u16 addr) = NULL;
void (*write_byte)(u16 addr, u8 val) = NULL;

/*
int main(int argc, const char *argv[]) {
    execute_init();

    while(true) {
        execute(fetch_byte());

        // ----- show the zero page graphically
        for(u16 i = 0; i < 16; i++) {
            for(u16 j = 0; j < 16; j++) {
                printf("%2x ", memory[i * 16 + j]);
            }
            putchar('\n');
        }
        getchar();
        // -----
    }
}
*/

u8 fetch_byte(void) {
    u8 result = read_byte(reg_pc);
    reg_pc++;
    return result;
}
