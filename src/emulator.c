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
#include "private/emulator.h"

#include <stdio.h>

#include "private/registers.h"
#include "private/execute.h"
#include "private/memory_io.h"

u8 (*cpu_read_byte)(u16 addr) = NULL;
void (*cpu_write_byte)(u16 addr, u8 val) = NULL;

void cpu_library_init(void) {
    cpu_execute_init();
    cpu_registers_init();
}

void cpu_debug_print_registers(FILE *stream) {
    fprintf(stream, "PC: %x, P: %x\n", reg_pc, reg_flags.as_byte);
    fprintf(stream, "A: %x, X: %x, Y: %x\n", reg_a, reg_x, reg_y);
}

void cpu_clock(void) {
    cpu_execute(fetch_byte());
}

void cpu_reset(void) {
    reg_pc = BYTES_TO_WORD(cpu_read_byte(0xfffc), cpu_read_byte(0xfffd));
}

void cpu_irq(void) {
    if(reg_flags.i)
        return;

    stack_push_word(reg_pc);

    reg_flags.b = 0;
    stack_push_byte(reg_flags.as_byte);
    reg_flags.b = 1;

    reg_flags.i = 1;
    reg_pc = BYTES_TO_WORD(cpu_read_byte(0xfffe), cpu_read_byte(0xffff));
}

void cpu_nmi(void) {
    stack_push_word(reg_pc);

    reg_flags.b = 0;
    stack_push_byte(reg_flags.as_byte);
    reg_flags.b = 1;

    reg_flags.i = 1;
    reg_pc = BYTES_TO_WORD(cpu_read_byte(0xfffa), cpu_read_byte(0xfffb));
}

u8 fetch_byte(void) {
    u8 result = cpu_read_byte(reg_pc);
    reg_pc++;
    return result;
}
