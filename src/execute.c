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

#include "address_modes.h"
#include "instructions.h"

#define SET(opcode, inst, addr_fn) operations[opcode] = (struct operation) {\
                                       inst, addr_fn\
                                   }

struct operation {
    void (*inst)(addr_function addr);
    addr_function addr; // this differs based on the addressing mode
};

static struct operation *operations;

void execute_init(void) {
    operations = calloc(256, sizeof(struct operation));

    /*SET(0x00, BRK, R_IMP);*/
}

void execute(u8 opcode) {
    struct operation op = operations[opcode];
    op.inst(op.addr);
}
