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
#include "instructions.h"

#include "registers.h"
#include "memory_io.h"

// ADC - add with carry
INS(ADC) {
    // TODO ADC
}

// AND - logical AND
INS(AND) {
    u8 val = mem_read_byte();

    reg_a &= val;

    reg_flags.z = (reg_a == 0);
    reg_flags.n = (reg_a & 0x80) != 0;
}

// ASL - arithmetic shift left
INS(ASL) {
    // TODO ASL
}

// BCC - branch if carry clear
INS(BCC) {
    i8 diff = mem_read_byte();

    if(!reg_flags.c)
        reg_pc += diff;
}

// BCS - branch if carry set
INS(BCS) {
    i8 diff = mem_read_byte();

    if(reg_flags.c)
        reg_pc += diff;
}

// BEQ - branch if equal
INS(BEQ) {
    i8 diff = mem_read_byte();

    if(reg_flags.z)
        reg_pc += diff;
}

// BIT - bit test
INS(BIT) {
    // TODO BIT
}

// BMI - branch if minus
INS(BMI) {
    i8 diff = mem_read_byte();

    if(reg_flags.n)
        reg_pc += diff;
}

// BNE - branch if not equal
INS(BNE) {
    i8 diff = mem_read_byte();

    if(!reg_flags.z)
        reg_pc += diff;
}

// BPL - branch if positive
INS(BPL) {
    i8 diff = mem_read_byte();

    if(!reg_flags.n)
        reg_pc += diff;
}

// BRK - force interrupt
INS(BRK) {
    // TODO BRK
}

// BVC - branch if overflow clear
INS(BVC) {
    i8 diff = mem_read_byte();

    if(!reg_flags.v)
        reg_pc += diff;
}

// BVS - branch if overflow set
INS(BVS) {
    i8 diff = mem_read_byte();

    if(reg_flags.v)
        reg_pc += diff;
}

// CLC - clear carry flag
INS(CLC) {
    reg_flags.c = 0;
}

// CLD - clear decimal mode
INS(CLD) {
    reg_flags.d = 0;
}

// CLI - clear interrupt disable
INS(CLI) {
    reg_flags.i = 0;
}

// CLV - clear overflow flag
INS(CLV) {
    reg_flags.v = 0;
}

// CMP - compare
INS(CMP) {
    u8 tocmp = mem_read_byte();

    reg_flags.c = (reg_a >= tocmp);
    reg_flags.z = (reg_a == tocmp);
    reg_flags.n = ((reg_a - tocmp) & 0x80) != 0;
}

// CPX - compare X register
INS(CPX) {
    u8 tocmp = mem_read_byte();

    reg_flags.c = (reg_x >= tocmp);
    reg_flags.z = (reg_x == tocmp);
    reg_flags.n = ((reg_x - tocmp) & 0x80) != 0;
}

// CPY - compare Y register
INS(CPY) {
    u8 tocmp = mem_read_byte();

    reg_flags.c = (reg_y >= tocmp);
    reg_flags.z = (reg_y == tocmp);
    reg_flags.n = ((reg_y - tocmp) & 0x80) != 0;
}

// DEC - decrement memory
INS(DEC) {
    u8 val = mem_read_byte() - 1;
    mem_write_byte(val);

    reg_flags.z = (val == 0);
    reg_flags.n = (val & 0x80) != 0;
}

// DEX - decrement X register
INS(DEX) {
    reg_x--;

    reg_flags.z = (reg_x == 0);
    reg_flags.n = (reg_x & 0x80) != 0;
}

// DEY - decrement Y register
INS(DEY) {
    reg_y--;

    reg_flags.z = (reg_y == 0);
    reg_flags.n = (reg_y & 0x80) != 0;
}

// EOR - exclusive OR
INS(EOR) {
    // TODO EOR
}

// INC - increment memory
INS(INC) {
    u8 val = mem_read_byte() + 1;
    mem_write_byte(val);

    reg_flags.z = (val == 0);
    reg_flags.n = (val & 0x80) != 0;
}

// INX - increment X register
INS(INX) {
    reg_x++;

    reg_flags.z = (reg_x == 0);
    reg_flags.n = (reg_x & 0x80) != 0;
}

// INY - increment Y register
INS(INY) {
    reg_y++;

    reg_flags.z = (reg_y == 0);
    reg_flags.n = (reg_y & 0x80) != 0;
}

// JMP - jump
INS(JMP) {
    // TODO JMP
}

// JSR - jump to subroutine
INS(JSR) {
    // TODO JSR
}

// LDA - load accumulator
INS(LDA) {
    reg_a = mem_read_byte();

    reg_flags.z = (reg_a == 0);
    reg_flags.n = (reg_a & 0x80) != 0;
}

// LDX - load X register
INS(LDX) {
    reg_x = mem_read_byte();

    reg_flags.z = (reg_x == 0);
    reg_flags.n = (reg_x & 0x80) != 0;
}

// LDY - load Y register
INS(LDY) {
    reg_y = mem_read_byte();

    reg_flags.z = (reg_y == 0);
    reg_flags.n = (reg_y & 0x80) != 0;
}

// LSR - logical shift right
INS(LSR) {
    // TODO LSR
}

// NOP - no operation
INS(NOP) {
}

// ORA - logical inclusive OR
INS(ORA) {
    // TODO ORA
}

// PHA - push accumulator
INS(PHA) {
    // TODO PHA
}

// PHP - push processor status
INS(PHP) {
    // TODO PHP
}

// PLA - pull accumulator
INS(PLA) {
    // TODO PLA
}

// PLP - pull processor status
INS(PLP) {
    // TODO PLP
}

// ROL - rotate left
INS(ROL) {
    // TODO ROL
}

// ROR - rotate right
INS(ROR) {
    // TODO ROR
}

// RTI - return from interrupt
INS(RTI) {
    // TODO RTI
}

// RTS - return from subroutine
INS(RTS) {
    // TODO RTS
}

// SBC - subtract with carry
INS(SBC) {
    // TODO SBC
}

// SEC - set carry flag
INS(SEC) {
    reg_flags.c = 1;
}

// SED - set decimal mode
INS(SED) {
    reg_flags.d = 1;
}

// SEI - set interrupt disable
INS(SEI) {
    reg_flags.i = 1;
}

// STA - store accumulator
INS(STA) {
    mem_write_byte(reg_a);
}

// STX - store X register
INS(STX) {
    mem_write_byte(reg_x);
}

// STY - store Y register
INS(STY) {
    mem_write_byte(reg_y);
}

// TAX - transfer accumulator to X
INS(TAX) {
    reg_x = reg_a;

    reg_flags.z = (reg_x == 0);
    reg_flags.n = (reg_x & 0x80) != 0;
}

// TAY - transfer accumulator to Y
INS(TAY) {
    reg_y = reg_a;

    reg_flags.z = (reg_y == 0);
    reg_flags.n = (reg_y & 0x80) != 0;
}

// TSX - transfer stack pointer to X
INS(TSX) {
    reg_x = reg_s;

    reg_flags.z = (reg_x == 0);
    reg_flags.n = (reg_x & 0x80) != 0;
}

// TXA - transfer X to accumulator
INS(TXA) {
    reg_a = reg_x;

    reg_flags.z = (reg_a == 0);
    reg_flags.n = (reg_a & 0x80) != 0;
}

// TXS - transfer X to stack pointer
INS(TXS) {
    reg_s = reg_x;
}

// TYA - transfer Y to accumulator
INS(TYA) {
    reg_a = reg_y;

    reg_flags.z = (reg_a == 0);
    reg_flags.n = (reg_a & 0x80) != 0;
}
