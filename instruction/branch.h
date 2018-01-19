#ifndef INSTRUCTION_BRANCH_H_INCLUDED
#define INSTRUCTION_BRANCH_H_INCLUDED

#include <stdint.h>
struct instruction_branch
{
    uint8_t     cond    : 0x4; // condition
    uint8_t     hard    : 0x3; // set 0x5
    uint8_t     L       : 0x1; // link bit
    uint32_t    offset  : 0x18;// offset
};

#endif
