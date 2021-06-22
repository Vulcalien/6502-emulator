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
#include "private/execute.h"

#include "private/instructions.h"
#include "private/memory_io.h"
#include "private/addressing.h"

struct operation {
    void (*inst)(void);
    u16 (*addressing)(void);
};

static struct operation *operations;

#define SET(opcode, inst, addressing_mode)\
            operations[opcode] = (struct operation) {\
                inst, addressing_mode\
            }

void cpu_execute(u8 opcode) {
    struct operation *op = &operations[opcode];

    mem_set_addressing(op->addressing);
    op->inst();

    mem_clear_addr_cache();
}

void cpu_execute_init(void) {
    operations = calloc(256, sizeof(struct operation));

    SET(0x69, ADC, A_IMM);
    SET(0x65, ADC, A_ZPG);
    SET(0x75, ADC, A_ZPX);
    SET(0x6d, ADC, A_ABS);
    SET(0x7d, ADC, A_ABX);
    SET(0x79, ADC, A_ABY);
    SET(0x61, ADC, A_INX);
    SET(0x71, ADC, A_INY);

    SET(0x29, AND, A_IMM);
    SET(0x25, AND, A_ZPG);
    SET(0x35, AND, A_ZPX);
    SET(0x2d, AND, A_ABS);
    SET(0x3d, AND, A_ABX);
    SET(0x39, AND, A_ABY);
    SET(0x21, AND, A_INX);
    SET(0x31, AND, A_INY);

    SET(0x0a, ASL, A_ACC);
    SET(0x06, ASL, A_ZPG);
    SET(0x16, ASL, A_ZPX);
    SET(0x0e, ASL, A_ABS);
    SET(0x1e, ASL, A_ABX);

    SET(0x90, BCC, A_REL);

    SET(0xb0, BCS, A_REL);

    SET(0xf0, BEQ, A_REL);

    SET(0x24, BIT, A_ZPG);
    SET(0x2c, BIT, A_ABS);

    SET(0x30, BMI, A_REL);

    SET(0xd0, BNE, A_REL);

    SET(0x10, BPL, A_REL);

    SET(0x00, BRK, A_IMP);

    SET(0x50, BVC, A_REL);

    SET(0x70, BVS, A_REL);

    SET(0x18, CLC, A_IMP);

    SET(0xd8, CLD, A_IMP);

    SET(0x58, CLI, A_IMP);

    SET(0xb8, CLV, A_IMP);

    SET(0xc9, CMP, A_IMM);
    SET(0xc5, CMP, A_ZPG);
    SET(0xd5, CMP, A_ZPX);
    SET(0xcd, CMP, A_ABS);
    SET(0xdd, CMP, A_ABX);
    SET(0xd9, CMP, A_ABY);
    SET(0xc1, CMP, A_INX);
    SET(0xd1, CMP, A_INY);

    SET(0xe0, CPX, A_IMM);
    SET(0xe4, CPX, A_ZPG);
    SET(0xec, CPX, A_ABS);

    SET(0xc0, CPY, A_IMM);
    SET(0xc4, CPY, A_ZPG);
    SET(0xcc, CPY, A_ABS);

    SET(0xc6, DEC, A_ZPG);
    SET(0xd6, DEC, A_ZPX);
    SET(0xce, DEC, A_ABS);
    SET(0xde, DEC, A_ABX);

    SET(0xca, DEX, A_IMP);

    SET(0x88, DEY, A_IMP);

    SET(0x49, EOR, A_IMM);
    SET(0x45, EOR, A_ZPG);
    SET(0x55, EOR, A_ZPX);
    SET(0x4d, EOR, A_ABS);
    SET(0x5d, EOR, A_ABX);
    SET(0x59, EOR, A_ABY);
    SET(0x41, EOR, A_INX);
    SET(0x51, EOR, A_INY);

    SET(0xe6, INC, A_ZPG);
    SET(0xf6, INC, A_ZPX);
    SET(0xee, INC, A_ABS);
    SET(0xfe, INC, A_ABX);

    SET(0xe8, INX, A_IMP);

    SET(0xc8, INY, A_IMP);

    SET(0x4c, JMP, A_ABS);
    SET(0x6c, JMP, A_IND);

    SET(0x20, JSR, A_ABS);

    SET(0xa9, LDA, A_IMM);
    SET(0xa5, LDA, A_ZPG);
    SET(0xb5, LDA, A_ZPX);
    SET(0xad, LDA, A_ABS);
    SET(0xbd, LDA, A_ABX);
    SET(0xb9, LDA, A_ABY);
    SET(0xa1, LDA, A_INX);
    SET(0xb1, LDA, A_INY);

    SET(0xa2, LDX, A_IMM);
    SET(0xa6, LDX, A_ZPG);
    SET(0xb6, LDX, A_ZPY);
    SET(0xae, LDX, A_ABS);
    SET(0xbe, LDX, A_ABY);

    SET(0xa0, LDY, A_IMM);
    SET(0xa4, LDY, A_ZPG);
    SET(0xb4, LDY, A_ZPX);
    SET(0xac, LDY, A_ABS);
    SET(0xbc, LDY, A_ABX);

    SET(0x4a, LSR, A_ACC);
    SET(0x46, LSR, A_ZPG);
    SET(0x56, LSR, A_ZPX);
    SET(0x4e, LSR, A_ABS);
    SET(0x5e, LSR, A_ABX);

    SET(0xea, NOP, A_IMP);

    SET(0x09, ORA, A_IMM);
    SET(0x05, ORA, A_ZPG);
    SET(0x15, ORA, A_ZPX);
    SET(0x0d, ORA, A_ABS);
    SET(0x1d, ORA, A_ABX);
    SET(0x19, ORA, A_ABY);
    SET(0x01, ORA, A_INX);
    SET(0x11, ORA, A_INY);

    SET(0x48, PHA, A_IMP);

    SET(0x08, PHP, A_IMP);

    SET(0x68, PLA, A_IMP);

    SET(0x28, PLP, A_IMP);

    SET(0x2a, ROL, A_ACC);
    SET(0x26, ROL, A_ZPG);
    SET(0x36, ROL, A_ZPX);
    SET(0x2e, ROL, A_ABS);
    SET(0x3e, ROL, A_ABX);

    SET(0x6a, ROR, A_ACC);
    SET(0x66, ROR, A_ZPG);
    SET(0x76, ROR, A_ZPX);
    SET(0x6e, ROR, A_ABS);
    SET(0x7e, ROR, A_ABX);

    SET(0x40, RTI, A_IMP);

    SET(0x60, RTS, A_IMP);

    SET(0xe9, SBC, A_IMM);
    SET(0xe5, SBC, A_ZPG);
    SET(0xf5, SBC, A_ZPX);
    SET(0xed, SBC, A_ABS);
    SET(0xfd, SBC, A_ABX);
    SET(0xf9, SBC, A_ABY);
    SET(0xe1, SBC, A_INX);
    SET(0xf1, SBC, A_INY);

    SET(0x38, SEC, A_IMP);

    SET(0xf8, SED, A_IMP);

    SET(0x78, SEI, A_IMP);

    SET(0x85, STA, A_ZPG);
    SET(0x95, STA, A_ZPX);
    SET(0x8d, STA, A_ABS);
    SET(0x9d, STA, A_ABX);
    SET(0x99, STA, A_ABY);
    SET(0x81, STA, A_INX);
    SET(0x91, STA, A_INY);

    SET(0x86, STX, A_ZPG);
    SET(0x96, STX, A_ZPY);
    SET(0x8e, STX, A_ABS);

    SET(0x84, STY, A_ZPG);
    SET(0x94, STY, A_ZPX);
    SET(0x8c, STY, A_ABS);

    SET(0xaa, TAX, A_IMP);

    SET(0xa8, TAY, A_IMP);

    SET(0xba, TSX, A_IMP);

    SET(0x8a, TXA, A_IMP);

    SET(0x9a, TXS, A_IMP);

    SET(0x98, TYA, A_IMP);
}
