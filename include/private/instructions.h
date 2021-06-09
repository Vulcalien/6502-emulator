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
#ifndef VULC_6502_EMULATOR_INSTRUCTIONS_P
#define VULC_6502_EMULATOR_INSTRUCTIONS_P

#include "private/emulator.h"

#define INS(x) void x(void)

// ADC - add with carry
extern INS(ADC);

// AND - logical AND
extern INS(AND);

// ASL - arithmetic shift left
extern INS(ASL);

// BCC - branch if carry clear
extern INS(BCC);

// BCS - branch if carry set
extern INS(BCS);

// BEQ - branch if equal
extern INS(BEQ);

// BIT - bit test
extern INS(BIT);

// BMI - branch if minus
extern INS(BMI);

// BNE - branch if not equal
extern INS(BNE);

// BPL - branch if positive
extern INS(BPL);

// BRK - force interrupt
extern INS(BRK);

// BVC - branch if overflow clear
extern INS(BVC);

// BVS - branch if overflow set
extern INS(BVS);

// CLC - clear carry flag
extern INS(CLC);

// CLD - clear decimal mode
extern INS(CLD);

// CLI - clear interrupt disable
extern INS(CLI);

// CLV - clear overflow flag
extern INS(CLV);

// CMP - compare
extern INS(CMP);

// CPX - compare X register
extern INS(CPX);

// CPY - compare Y register
extern INS(CPY);

// DEC - decrement memory
extern INS(DEC);

// DEX - decrement X register
extern INS(DEX);

// DEY - decrement Y register
extern INS(DEY);

// EOR - exclusive OR
extern INS(EOR);

// INC - increment memory
extern INS(INC);

// INX - increment X register
extern INS(INX);

// INY - increment Y register
extern INS(INY);

// JMP - jump
extern INS(JMP);

// JSR - jump to subroutine
extern INS(JSR);

// LDA - load accumulator
extern INS(LDA);

// LDX - load X register
extern INS(LDX);

// LDY - load Y register
extern INS(LDY);

// LSR - logical shift right
extern INS(LSR);

// NOP - no operation
extern INS(NOP);

// ORA - logical inclusive OR
extern INS(ORA);

// PHA - push accumulator
extern INS(PHA);

// PHP - push processor status
extern INS(PHP);

// PLA - pull accumulator
extern INS(PLA);

// PLP - pull processor status
extern INS(PLP);

// ROL - rotate left
extern INS(ROL);

// ROR - rotate right
extern INS(ROR);

// RTI - return from interrupt
extern INS(RTI);

// RTS - return from subroutine
extern INS(RTS);

// SBC - subtract with carry
extern INS(SBC);

// SEC - set carry flag
extern INS(SEC);

// SED - set decimal mode
extern INS(SED);

// SEI - set interrupt disable
extern INS(SEI);

// STA - store accumulator
extern INS(STA);

// STX - store X register
extern INS(STX);

// STY - store Y register
extern INS(STY);

// TAX - transfer accumulator to X
extern INS(TAX);

// TAY - transfer accumulator to Y
extern INS(TAY);

// TSX - transfer stack pointer to X
extern INS(TSX);

// TXA - transfer X to accumulator
extern INS(TXA);

// TXS - transfer X to stack pointer
extern INS(TXS);

// TYA - transfer Y to accumulator
extern INS(TYA);

#endif // VULC_6502_EMULATOR_INSTRUCTIONS_P
