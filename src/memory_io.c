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
#include "private/memory_io.h"

#include "private/registers.h"
#include "private/addressing.h"

static u16 (*mem_addressing)(void) = NULL;

// Some instructions need to read and then write to the same address,
// so store the address and return it instead of fetching more bytes
static u16 address_cache;
static bool is_cache_valid = false;

u16 mem_get_addr(void) {
    if(!is_cache_valid) {
        is_cache_valid = true;
        address_cache = mem_addressing();
    }
    return address_cache;
}

// read/write
u8 mem_read_byte(void) {
    if(mem_addressing == A_ACC)
        return reg_a;

    if(mem_addressing == A_IMM || mem_addressing == A_REL)
        return fetch_byte();

    return cpu_read_byte(mem_get_addr());
}

u16 mem_read_word(void) {
    u16 addr = mem_get_addr();
    return BYTES_TO_WORD(cpu_read_byte(addr), cpu_read_byte(addr + 1));
}

void mem_write_byte(u8 byte) {
    if(mem_addressing == A_ACC)
        reg_a = byte;
    else
        cpu_write_byte(mem_get_addr(), byte);
}

// stack
u8 stack_pull_byte(void) {
    reg_s++;
    return cpu_read_byte(0x100 + reg_s);
}

u16 stack_pull_word(void) {
    // TODO pull word
    return -1;
}

void stack_push_byte(u8 byte) {
    cpu_write_byte(0x100 + reg_s, byte);
    reg_s--;
}

void stack_push_word(u16 word) {
    // TODO push word
}

// addressing
void mem_set_addressing(u16 (*addr)(void)) {
    mem_addressing = addr;
}

void mem_clear_addr_cache(void) {
    is_cache_valid = false;
}
