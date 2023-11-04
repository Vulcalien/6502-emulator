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
#include "private/instructions.h"

#include "private/registers.h"
#include "private/memory_io.h"

static void add_operation(u8 to_add) {
    if(reg_flags.d) {
        // TODO implement decimal mode
    } else {
        u8 old_a = reg_a;

        u16 tmp = reg_a + to_add;
        reg_a = tmp; // <u8> <- <u16>

        reg_flags.c = (tmp & 0xff00) != 0;
        reg_flags.z = (reg_a == 0);
        reg_flags.v = ((old_a ^ reg_a) & (to_add ^ reg_a) & 0x80) != 0;
        reg_flags.n = (reg_a & 0x80) != 0;
    }
}

// ADC - add with carry
INS(ADC) {
    add_operation(mem_read_byte() + reg_flags.c);
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
    u8 val = mem_read_byte();

    reg_flags.c = (val & 0x80) != 0;

    val <<= 1;
    mem_write_byte(val);

    reg_flags.z = (val == 0);
    reg_flags.n = (val & 0x80) != 0;
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
    u8 val = mem_read_byte();

    reg_flags.z = (reg_a & val) == 0;
    reg_flags.v = (val & 0x40) != 0;
    reg_flags.n = (val & 0x80) != 0;
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
    fetch_byte();

    stack_push_word(reg_pc);
    stack_push_byte(reg_flags.as_byte);

    reg_flags.i = 1;
    reg_pc = BYTES_TO_WORD(cpu_read_byte(0xfffe), cpu_read_byte(0xffff));
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
    u8 val = mem_read_byte();

    reg_a ^= val;

    reg_flags.z = (reg_a == 0);
    reg_flags.n = (reg_a & 0x80) != 0;
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
    reg_pc = mem_get_addr();
}

// JSR - jump to subroutine
INS(JSR) {
    u16 addr = mem_get_addr();

    stack_push_word(reg_pc - 1);
    reg_pc = addr;
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
    u8 val = mem_read_byte();

    reg_flags.c = (val & 0x01) != 0;

    val >>= 1;
    mem_write_byte(val);

    reg_flags.z = (val == 0);
    reg_flags.n = (val & 0x80) != 0;
}

// NOP - no operation
INS(NOP) {
}

// ORA - logical inclusive OR
INS(ORA) {
    u8 val = mem_read_byte();

    reg_a |= val;

    reg_flags.z = (reg_a == 0);
    reg_flags.n = (reg_a & 0x80) != 0;
}

// PHA - push accumulator
INS(PHA) {
    stack_push_byte(reg_a);
}

// PHP - push processor status
INS(PHP) {
    stack_push_byte(reg_flags.as_byte);
}

// PLA - pull accumulator
INS(PLA) {
    reg_a = stack_pull_byte();

    reg_flags.z = (reg_a == 0);
    reg_flags.n = (reg_a & 0x80) != 0;
}

// PLP - pull processor status
INS(PLP) {
    reg_flags.as_byte = stack_pull_byte();
    reg_flags.b = 1;
    reg_flags.u = 1;
}

// ROL - rotate left
INS(ROL) {
    u8 val = mem_read_byte();

    u8 old_c = reg_flags.c;
    reg_flags.c = (val & 0x80) != 0;

    val = (val << 1) | old_c;
    mem_write_byte(val);

    reg_flags.z = (val == 0);
    reg_flags.n = (val & 0x80) != 0;
}

// ROR - rotate right
INS(ROR) {
    u8 val = mem_read_byte();

    u8 old_c = reg_flags.c;
    reg_flags.c = (val & 0x01) != 0;

    val = (val >> 1) | (old_c << 7);
    mem_write_byte(val);

    reg_flags.z = (val == 0);
    reg_flags.n = (val & 0x80) != 0;
}

// RTI - return from interrupt
INS(RTI) {
    reg_flags.as_byte = stack_pull_byte();
    reg_flags.b = 1;
    reg_flags.u = 1;

    reg_pc = stack_pull_word();
}

// RTS - return from subroutine
INS(RTS) {
    reg_pc = stack_pull_word() + 1;
}

// SBC - subtract with carry
INS(SBC) {
    add_operation(-mem_read_byte() - !reg_flags.c);
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
