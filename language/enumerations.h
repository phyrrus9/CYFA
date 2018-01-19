#ifndef ENUMERATIONS_H_INCLUDED
#define ENUMERATIONS_H_INCLUDED

enum language_token
{
    kTOKEN_NULL = 0, /* terminator for language rule list */
    kTOKEN_UNDEF,
    kTOKEN_CHARACTER,
    /* basic tokens */
    kTOKEN_MNEMONIC,
    kTOKEN_REGISTER,
    kTOKEN_CONSTANT,
    kTOKEN_EXPRESSION,
    /* evaluated tokens */
    kTOKEN_OPCODE,
    kTOKEN_CONDITION,
    kTOKEN_ACCESSOR
};

enum language_opcode
{
    /* Data processing */
    kOPCODE_AND = 0x00001,
    kOPCODE_EOR = 0x00002,
    kOPCODE_SUB = 0x00004,
    kOPCODE_RSB = 0x00008,
    kOPCODE_ADD = 0x00010,
    kOPCODE_ADC = 0x00020,
    kOPCODE_SBC = 0x00040,
    kOPCODE_RSC = 0x00080,
    kOPCODE_TST = 0x00100,
    kOPCODE_TEQ = 0x00200,
    kOPCODE_CMP = 0x00400,
    kOPCODE_CMN = 0x00800,
    kOPCODE_ORR = 0x01000,
    kOPCODE_MOV = 0x02000,
    kOPCODE_BIC = 0x04000,
    kOPCODE_MVN = 0x08000,
    /* single data transfer */
    kOPCODE_LDR = 0x10000,
    kOPCODE_STR = 0x20000,
    /* branches */
    kOPCODE_B   = 0x40000,
    kOPCODE_BL  = 0x80000
};

#endif // ENUMERATIONS_H_INCLUDED
