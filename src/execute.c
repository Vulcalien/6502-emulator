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
#include "execute.h"

#include "instructions.h"
#include "memory_io.h"


#define SET(opcode, inst, addressing_mode)\
            operations[opcode] = (struct operation) {\
                inst, addressing_mode\
            }

// addressing modes
#define IMP NULL,          NULL,           NULL
#define ACC read_byte_acc, NULL, write_byte_acc
#define IMM read_byte_imm, NULL,           NULL
// TODO continue...

struct operation {
    void (*inst)(void);

    u8   (*read_byte) (void);
    u16  (*read_word) (void);
    void (*write_byte)(u8 byte);
};

static struct operation *operations;

void execute_init(void) {
    operations = calloc(256, sizeof(struct operation));

    SET(0x00, BRK, IMP);
}

void execute(u8 opcode) {
    struct operation *op = &operations[opcode];

    mem_read_byte = op->read_byte;
    mem_read_word = op->read_word;
    mem_write_byte = op->write_byte;

    op->inst();
}
