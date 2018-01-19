#ifndef INSTRUCTION_H_INCLUDED
#define INSTRUCTION_H_INCLUDED

#include <instruction/data.h>
#include <instruction/transfer.h>
#include <instruction/branch.h>

union instruction
{
    struct instruction_data         DP;     // data processing
    struct instruction_transfer     DT;     // single data transfer
    struct instruction_branch       BR;     // branch
};

enum instruction_type
{
    kINSTRUCTION_DATA,
    kINSTRUCTION_TRANSFER,
    kINSTRUCTION_BRANCH,
    kINSTRUCTION_UNDEF
};

enum instruction_condition
{
    kCONDITION_EQ,
    kCONDITION_NE,
    kCONDITION_CS,
    kCONDITION_CC,
    kCONDITION_MI,
    kCONDITION_PL,
    kCONDITION_VS,
    kCONDITION_VC,
    kCONDITION_HI,
    kCONDITION_LS,
    kCONDITION_GE,
    kCONDITION_LT,
    kCONDITION_GT,
    kCONDITION_LE,
    kCONDITION_AL,
    kCONDITION_NV
};

void instruction_init(union instruction *, enum instruction_type);
uint32_t instruction_encode(union instruction *);

#endif
