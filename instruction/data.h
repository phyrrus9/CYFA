#ifndef INSTRUCTION_DATA_H_INCLUDED
#define INSTRUCTION_DATA_H_INCLUDED

#include <stdint.h>

/* fixes */
enum instruction_data_operand2_register_shift_type
{
    kDATA_OP2_LOGIC_LEFT      = 0x0,
    kDATA_OP2_LOGIC_RIGHT     = 0x1,
    kDATA_OP2_LOGIC_ARR_RIGHT = 0x2,
    kDATA_OP2_LOGIC_ROT_RIGHT = 0x3,
};
struct instruction_data_operand_register_shift_imm
{
    uint8_t hard0: 0x1; // set 0x0
    uint8_t type : 0x2; // see enum instruction_data_operand2_register_shift_type
    uint8_t imm  : 0x5; // shift ammount
};
struct instruction_data_operand_register_shift_reg
{
    uint8_t hard1 : 0x1; // set 0x1
    uint8_t type  : 0x2; // see enum instruction_data_operand2_register_shift_type
    uint8_t hard0 : 0x1; // set 0x0
    uint8_t reg   : 0x4; // register holding value
};
union instruction_data_operand2_register_high
{
    struct instruction_data_operand_register_shift_imm imm;
    struct instruction_data_operand_register_shift_reg reg;
};
struct instruction_data_operand2_register
{
    uint8_t Rm : 0x4; // op2 as register
    union instruction_data_operand2_register_high shift;
};
/* operand2 for data processing */
struct instruction_data_operand2_immediate
{
    uint8_t     imm;           // 8-bit unsigned immediate value to be rotated
    uint8_t     rotate  : 0x4; // rotate value (multiplied by 2 by CPU)
};
union instruction_data_operand2
{
    struct instruction_data_operand2_immediate imm;
    struct instruction_data_operand2_register reg;
};
/* structure for instruction */
struct instruction_data
{
    uint8_t     cond    : 0x4; // condition
    uint8_t     hard    : 0x2; // set 0x0
    uint8_t     I       : 0x1; // immediate bit
    uint8_t     opcode  : 0x4; // operation code
    uint8_t     S       : 0x1; // condition set
    uint8_t     Rn      : 0x4; // 1st operand reg
    uint8_t     Rd      : 0x4; // destination reg
    union instruction_data_operand2 op2; // 2nd operand (imm=0 : reg, imm=1 : imm)
};

#endif
