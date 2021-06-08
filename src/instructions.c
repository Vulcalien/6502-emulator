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
INS(ADC_imm) {
    // TODO ADC_imm
}
INS(ADC_zpg) {
    // TODO ADC_zpg
}
INS(ADC_zpx) {
    // TODO ADC_zpx
}
INS(ADC_abs) {
    // TODO ADC_abs
}
INS(ADC_abx) {
    // TODO ADC_abx
}
INS(ADC_aby) {
    // TODO ADC_aby
}
INS(ADC_inx) {
    // TODO ADC_inx
}
INS(ADC_iny) {
    // TODO ADC_iny
}

// AND - logical AND
INS(AND_imm) {
    // TODO AND_imm
}
INS(AND_zpg) {
    // TODO AND_zpg
}
INS(AND_zpx) {
    // TODO AND_zpx
}
INS(AND_abs) {
    // TODO AND_abs
}
INS(AND_abx) {
    // TODO AND_abx
}
INS(ANX_aby) {
    // TODO ANX_aby
}
INS(AND_inx) {
    // TODO AND_inx
}
INS(AND_iny) {
    // TODO AND_iny
}

// ASL - arithmetic shift left
INS(ASL_acc) {
    // TODO ASL_acc
}
INS(ASL_zpg) {
    // TODO ASL_zpg
}
INS(ASL_zpx) {
    // TODO ASL_zpx
}
INS(ASL_abs) {
    // TODO ASL_abs
}
INS(ASL_abx) {
    // TODO ASL_abx
}

// BCC - branch if carry clear
INS(BCC_rel) {
    // TODO BCC_rel
}

// BCS - branch if carry set
INS(BCS_rel) {
    // TODO BCS_rel
}

// BEQ - branch if equal
INS(BEQ_rel) {
    // TODO BEQ_rel
}

// BIT - bit test
INS(BIT_zpg) {
    // TODO BIT_zpg
}
INS(BIT_abs) {
    // TODO BIT_abs
}

// BMI - branch if minus
INS(BMI_rel) {
    // TODO BMI_rel
}

// BNE - branch if not equal
INS(BNE_rel) {
    // TODO BNE_rel
}

// BPL - branch if positive
INS(BPL_rel) {
    // TODO BPL_rel
}

// BRK - force interrupt
INS(BRK_imp) {
    // TODO BRK_imp
}

// BVC - branch if overflow clear
INS(BVC_rel) {
    // TODO BVC_rel
}

// BVS - branch if overflow set
INS(BVS_rel) {
    // TODO BVS_rel
}

// CLC - clear carry flag
INS(CLC_imp) {
    // TODO CLC_imp
}

// CLD - clear decimal mode
INS(CLD_imp) {
    // TODO CLD_imp
}

// CLI - clear interrupt disable
INS(CLI_imp) {
    // TODO CLI_imp
}

// CLV - clear overflow flag
INS(CLV_imp) {
    // TODO CLV_imp
}

// CMP - compare
INS(CMP_imm) {
    // TODO CMP_imm
}
INS(CMP_zpg) {
    // TODO CMP_zpg
}
INS(CMP_zpx) {
    // TODO CMP_zpx
}
INS(CMP_abs) {
    // TODO CMP_abs
}
INS(CMP_abx) {
    // TODO CMP_abx
}
INS(CMP_aby) {
    // TODO CMP_aby
}
INS(CMP_inx) {
    // TODO CMP_inx
}
INS(CMP_iny) {
    // TODO CMP_iny
}

// CPX - compare X register
INS(CPX_imm) {
    // TODO CPX_imm
}
INS(CPX_zpg) {
    // TODO CPX_zpg
}
INS(CPX_abs) {
    // TODO CPX_abs
}

// CPY - compare Y register
INS(CPY_imm) {
    // TODO CPY_imm
}
INS(CPY_zpg) {
    // TODO CPY_zpg
}
INS(CPY_abs) {
    // TODO CPY_abs
}

// DEC - decrement memory
INS(DEC_zpg) {
    // TODO DEC_zpg
}
INS(DEC_zpx) {
    // TODO DEC_zpx
}
INS(DEC_abs) {
    // TODO DEC_abs
}
INS(DEC_abx) {
    // TODO DEC_abx
}

// DEX - decrement X register
INS(DEX_imp) {
    // TODO DEX_imp
}

// DEY - decrement Y register
INS(DEY_imp) {
    // TODO DEY_imp
}

// EOR - exclusive OR
INS(EOR_imm) {
    // TODO EOR_imm
}
INS(EOR_zpg) {
    // TODO EOR_zpg
}
INS(EOR_zpx) {
    // TODO EOR_zpx
}
INS(EOR_abs) {
    // TODO EOR_abs
}
INS(EOR_abx) {
    // TODO EOR_abx
}
INS(EOR_aby) {
    // TODO EOR_aby
}
INS(EOR_inx) {
    // TODO EOR_inx
}
INS(EOR_iny) {
    // TODO EOR_iny
}

// INC - increment memory
INS(INC_zpg) {
    // TODO INC_zpg
}
INS(INC_zpx) {
    // TODO INC_zpx
}
INS(INC_abs) {
    // TODO INC_abs
}
INS(INC_abx) {
    // TODO INC_abx
}

// INX - increment X register
INS(INX_imp) {
    // TODO INX_imp
}

// INY - increment Y register
INS(INY_imp) {
    // TODO INY_imp
}

// JMP - jump
INS(JMP_abs) {
    // TODO JMP_abs
}
INS(JMP_ind) {
    // TODO JMP_ind
}

// JSR - jump to subroutine
INS(JSR_abs) {
    // TODO JSR_abs
}

// LDA - load accumulator
INS(LDA_imm) {
    // TODO LDA_imm
}
INS(LDA_zpg) {
    // TODO LDA_zpg
}
INS(LDA_zpx) {
    // TODO LDA_zpx
}
INS(LDA_abs) {
    // TODO LDA_abs
}
INS(LDA_abx) {
    // TODO LDA_abx
}
INS(LDA_aby) {
    // TODO LDA_aby
}
INS(LDA_inx) {
    // TODO LDA_inx
}
INS(LDA_iny) {
    // TODO LDA_iny
}

// LDX - load X register
INS(LDX_imm) {
    // TODO LDX_imm
}
INS(LDX_zpg) {
    // TODO LDX_zpg
}
INS(LDX_zpy) {
    // TODO LDX_zpy
}
INS(LDX_abs) {
    // TODO LDX_abs
}
INS(LDX_aby) {
    // TODO LDX_aby
}

// LDY - load Y register
INS(LDY_imm) {
    // TODO LDY_imm
}
INS(LDY_zpg) {
    // TODO LDY_zpg
}
INS(LDY_zpx) {
    // TODO LDY_zpx
}
INS(LDY_abs) {
    // TODO LDY_abs
}
INS(LDY_abx) {
    // TODO LDY_abx
}

// LSR - logical shift right
INS(LSR_acc) {
    // TODO LSR_acc
}
INS(LSR_zpg) {
    // TODO LSR_zpg
}
INS(LSR_zpx) {
    // TODO LSR_zpx
}
INS(LSR_abs) {
    // TODO LSR_abs
}
INS(LSR_abx) {
    // TODO LSR_abx
}

// NOP - no operation
INS(NOP_imp) {
    // TODO NOP_imp
}

// ORA - logical inclusive OR
INS(ORA_imm) {
    // TODO ORA_imm
}
INS(ORA_zpg) {
    // TODO ORA_zpg
}
INS(ORA_zpx) {
    // TODO ORA_zpx
}
INS(ORA_abs) {
    // TODO ORA_abs
}
INS(ORA_abx) {
    // TODO ORA_abx
}
INS(ORA_aby) {
    // TODO ORA_aby
}
INS(ORA_inx) {
    // TODO ORA_inx
}
INS(ORA_iny) {
    // TODO ORA_iny
}

// PHA - push accumulator
INS(PHA_imp) {
    // TODO PHA_imp
}

// PHP - push processor status
INS(PHP_imp) {
    // TODO PHP_imp
}

// PLA - pull accumulator
INS(PLA_imp) {
    // TODO PLA_imp
}

// PLP - pull processor status
INS(PLP_imp) {
    // TODO PLP_imp
}

// ROL - rotate left
INS(ROL_acc) {
    // TODO ROL_acc
}
INS(ROL_zpg) {
    // TODO ROL_zpg
}
INS(ROL_zpx) {
    // TODO ROL_zpx
}
INS(ROL_abs) {
    // TODO ROL_abs
}
INS(ROL_abx) {
    // TODO ROL_abx
}

// ROR - rotate right
INS(ROR_acc) {
    // TODO ROR_acc
}
INS(ROR_zpg) {
    // TODO ROR_zpg
}
INS(ROR_zpx) {
    // TODO ROR_zpx
}
INS(ROR_abs) {
    // TODO ROR_abs
}
INS(ROR_abx) {
    // TODO ROR_abx
}

// RTI - return from interrupt
INS(RTI_imp) {
    // TODO RTI_imp
}

// RTS - return from subroutine
INS(RTS_imp) {
    // TODO RTS_imp
}

// SBC - subtract with carry
INS(SBC_imm) {
    // TODO SBC_imm
}
INS(SBC_zpg) {
    // TODO SBC_zpg
}
INS(SBC_zpx) {
    // TODO SBC_zpx
}
INS(SBC_abs) {
    // TODO SBC_abs
}
INS(SBC_abx) {
    // TODO SBC_abx
}
INS(SBC_aby) {
    // TODO SBC_aby
}
INS(SBC_inx) {
    // TODO SBC_inx
}
INS(SBC_iny) {
    // TODO SBC_iny
}

// SEC - set carry flag
INS(SEC_imp) {
    // TODO SEC_imp
}

// SED - set decimal flag
INS(SED_imp) {
    // TODO SED_imp
}

// SEI - set interrupt disable
INS(SEI_imp) {
    // TODO SEI_imp
}

// STA - store accumulator
INS(STA_zpg) {
    // TODO STA_zpg
}
INS(STA_zpx) {
    // TODO STA_zpx
}
INS(STA_abs) {
    // TODO STA_abs
}
INS(STA_abx) {
    // TODO STA_abx
}
INS(STA_aby) {
    // TODO STA_aby
}
INS(STA_inx) {
    // TODO STA_inx
}
INS(STA_iny) {
    // TODO STA_iny
}

// STX - store X register
INS(STX_zpg) {
    // TODO STX_zpg
}
INS(STX_zpy) {
    // TODO STX_zpy
}
INS(STX_abs) {
    // TODO STX_abs
}

// STY - store Y register
INS(STY_zpg) {
    // TODO STY_zpg
}
INS(STY_zpx) {
    // TODO STY_zpx
}
INS(STY_abs) {
    // TODO STY_abs
}

// TAX - transfer accumulator to X
INS(TAX_imp) {
    // TODO TAX_imp
}

// TAY - transfer accumulator to Y
INS(TAY_imp) {
    // TODO TAY_imp
}

// TSX - transfer stack pointer to X
INS(TSA_imp) {
    // TODO TSA_imp
}

// TXA - transfer X to accumulator
INS(TXA_imp) {
    // TODO TXA_imp
}

// TXS - transfer X to stack pointer
INS(TXS_imp) {
    // TODO TXS_imp
}

// TYA - transfer Y to accumulator
INS(TYA_imp) {
    // TODO TYA_imp
}
