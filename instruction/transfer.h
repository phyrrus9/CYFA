#ifndef INSTRUCTION_TRANSFER_H_INCLUDED
#define INSTRUCTION_TRANSFER_H_INCLUDED

#include <stdint.h>
struct instruction_transfer
{
    uint8_t     cond    : 0x4; // condition
    uint8_t     hard    : 0x2; // set 0x1
    uint8_t     I       : 0x1; // offset is immediate value (set 0)
    uint8_t     P       : 0x1; // pre/post index (set 1)
    uint8_t     U       : 0x1; // up/down bit (negative sign for offset)
    uint8_t     B       : 0x1; // byte/word bit (set 0 for word)
    uint8_t     W       : 0x1; // write-back register (set 0)
    uint8_t     Rn      : 0x4; // source register
    uint8_t     Rd      : 0x4; // destination register
    uint16_t    offset  : 0xC; // immediate/offset
};

#endif
