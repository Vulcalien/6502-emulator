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
#include "addressing.h"

#define SET(opcode, inst, addressing_mode)\
            operations[opcode] = (struct operation) {\
                inst, addressing_mode\
            }

struct operation {
    void (*inst)(void);
    u16 (*addressing)(void);
};

static struct operation *operations;

void execute_init(void) {
    operations = calloc(256, sizeof(struct operation));

    SET(0x00, BRK, A_IMP);
}

void execute(u8 opcode) {
    struct operation *op = &operations[opcode];

    mem_addressing = op->addressing;
    op->inst();

    mem_clear_addr_cache();
}
