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
#ifndef VULC_6502_EMULATOR_INSTRUCTIONS
#define VULC_6502_EMULATOR_INSTRUCTIONS

#include "emulator.h"

#define INS(x) void x(void)

/* Addressing mode:
 * imp = implicit
 * acc = accumulator
 * imm = immediate
 * zpg = zero page
 * zpx = zero page X
 * zpy = zero page Y
 * rel = relative
 * abs = absolute
 * abx = absolute X
 * aby = absolute Y
 * ind = indirect
 * inx = indirect X
 * iny = indirect Y
 */

// ADC - add with carry
extern INS(ADC_imm);
extern INS(ADC_zpg);
extern INS(ADC_zpx);
extern INS(ADC_abs);
extern INS(ADC_abx);
extern INS(ADC_aby);
extern INS(ADC_inx);
extern INS(ADC_iny);

// AND - logical AND
extern INS(AND_imm);
extern INS(AND_zpg);
extern INS(AND_zpx);
extern INS(AND_abs);
extern INS(AND_abx);
extern INS(ANX_aby);
extern INS(AND_inx);
extern INS(AND_iny);

// ASL - arithmetic shift left
extern INS(ASL_acc);
extern INS(ASL_zpg);
extern INS(ASL_zpx);
extern INS(ASL_abs);
extern INS(ASL_abx);

// BCC - branch if carry clear
extern INS(BCC_rel);

// BCS - branch if carry set
extern INS(BCS_rel);

// BEQ - branch if equal
extern INS(BEQ_rel);

// BIT - bit test
extern INS(BIT_zpg);
extern INS(BIT_abs);

// BMI - branch if minus
extern INS(BMI_rel);

// BNE - branch if not equal
extern INS(BNE_rel);

// BPL - branch if positive
extern INS(BPL_rel);

// BRK - force interrupt
extern INS(BRK_imp);

// BVC - branch if overflow clear
extern INS(BVC_rel);

// BVS - branch if overflow set
extern INS(BVS_rel);

// CLC - clear carry flag
extern INS(CLC_imp);

// CLD - clear decimal mode
extern INS(CLD_imp);

// CLI - clear interrupt disable
extern INS(CLI_imp);

// CLV - clear overflow flag
extern INS(CLV_imp);

// CMP - compare
extern INS(CMP_imm);
extern INS(CMP_zpg);
extern INS(CMP_zpx);
extern INS(CMP_abs);
extern INS(CMP_abx);
extern INS(CMP_aby);
extern INS(CMP_inx);
extern INS(CMP_iny);

// CPX - compare X register
extern INS(CPX_imm);
extern INS(CPX_zpg);
extern INS(CPX_abs);

// CPY - compare Y register
extern INS(CPY_imm);
extern INS(CPY_zpg);
extern INS(CPY_abs);

// DEC - decrement memory
extern INS(DEC_zpg);
extern INS(DEC_zpx);
extern INS(DEC_abs);
extern INS(DEC_abx);

// DEX - decrement X register
extern INS(DEX_imp);

// DEY - decrement Y register
extern INS(DEY_imp);

// EOR - exclusive OR
extern INS(EOR_imm);
extern INS(EOR_zpg);
extern INS(EOR_zpx);
extern INS(EOR_abs);
extern INS(EOR_abx);
extern INS(EOR_aby);
extern INS(EOR_inx);
extern INS(EOR_iny);

// INC - increment memory
extern INS(INC_zpg);
extern INS(INC_zpx);
extern INS(INC_abs);
extern INS(INC_abx);

// INX - increment X register
extern INS(INX_imp);

// INY - increment Y register
extern INS(INY_imp);

// JMP - jump
extern INS(JMP_abs);
extern INS(JMP_ind);

// JSR - jump to subroutine
extern INS(JSR_abs);

// LDA - load accumulator
extern INS(LDA_imm);
extern INS(LDA_zpg);
extern INS(LDA_zpx);
extern INS(LDA_abs);
extern INS(LDA_abx);
extern INS(LDA_aby);
extern INS(LDA_inx);
extern INS(LDA_iny);

// LDX - load X register
extern INS(LDX_imm);
extern INS(LDX_zpg);
extern INS(LDX_zpy);
extern INS(LDX_abs);
extern INS(LDX_aby);

// LDY - load Y register
extern INS(LDY_imm);
extern INS(LDY_zpg);
extern INS(LDY_zpx);
extern INS(LDY_abs);
extern INS(LDY_abx);

// LSR - logical shift right
extern INS(LSR_acc);
extern INS(LSR_zpg);
extern INS(LSR_zpx);
extern INS(LSR_abs);
extern INS(LSR_abx);

// NOP - no operation
INS(NOP_imp) {
}

// ORA - logical inclusive OR
extern INS(ORA_imm);
extern INS(ORA_zpg);
extern INS(ORA_zpx);
extern INS(ORA_abs);
extern INS(ORA_abx);
extern INS(ORA_aby);
extern INS(ORA_inx);
extern INS(ORA_iny);

// PHA - push accumulator
extern INS(PHA_imp);

// PHP - push processor status
extern INS(PHP_imp);

// PLA - pull accumulator
extern INS(PLA_imp);

// PLP - pull processor status
extern INS(PLP_imp);

// ROL - rotate left
extern INS(ROL_acc);
extern INS(ROL_zpg);
extern INS(ROL_zpx);
extern INS(ROL_abs);
extern INS(ROL_abx);

// ROR - rotate right
extern INS(ROR_acc);
extern INS(ROR_zpg);
extern INS(ROR_zpx);
extern INS(ROR_abs);
extern INS(ROR_abx);

// RTI - return from interrupt
extern INS(RTI_imp);

// RTS - return from subroutine
extern INS(RTS_imp);

// SBC - subtract with carry
extern INS(SBC_imm);
extern INS(SBC_zpg);
extern INS(SBC_zpx);
extern INS(SBC_abs);
extern INS(SBC_abx);
extern INS(SBC_aby);
extern INS(SBC_inx);
extern INS(SBC_iny);

// SEC - set carry flag
extern INS(SEC_imp);

// SED - set decimal flag
extern INS(SED_imp);

// SEI - set interrupt disable
extern INS(SEI_imp);

// STA - store accumulator
extern INS(STA_zpg);
extern INS(STA_zpx);
extern INS(STA_abs);
extern INS(STA_abx);
extern INS(STA_aby);
extern INS(STA_inx);
extern INS(STA_iny);

// STX - store X register
extern INS(STX_zpg);
extern INS(STX_zpy);
extern INS(STX_abs);

// STY - store Y register
extern INS(STY_zpg);
extern INS(STY_zpx);
extern INS(STY_abs);

// TAX - transfer accumulator to X
extern INS(TAX_imp);

// TAY - transfer accumulator to Y
extern INS(TAY_imp);

// TSX - transfer stack pointer to X
extern INS(TSA_imp);

// TXA - transfer X to accumulator
extern INS(TXA_imp);

// TXS - transfer X to stack pointer
extern INS(TXS_imp);

// TYA - transfer Y to accumulator
extern INS(TYA_imp);

#endif // VULC_6502_EMULATOR_INSTRUCTIONS
