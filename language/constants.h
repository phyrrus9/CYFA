#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

#define C_OPCODES_DP \
    kOPCODE_AND | \
    kOPCODE_EOR | \
    kOPCODE_SUB | \
    kOPCODE_RSB | \
    kOPCODE_ADD | \
    kOPCODE_ADC | \
    kOPCODE_SBC | \
    kOPCODE_RSC | \
    kOPCODE_TST | \
    kOPCODE_TEQ | \
    kOPCODE_CMP | \
    kOPCODE_CMN | \
    kOPCODE_ORR | \
    kOPCODE_MOV | \
    kOPCODE_BIC | \
    kOPCODE_MVN
#define C_OPCODES_DT \
    kOPCODE_LDR |\
    kOPCODE_STR
#define C_OPCODES_BR \
    kOPCODE_B   | \
    kOPCODE_BL

/* logical group data processing */
#define CG_OPCODES_LGC \
    kOPCODE_AND | \
    kOPCODE_EOR | \
    kOPCODE_ORR | \
    kOPCODE_BIC | \
    kOPCODE_MVN
#define CG_OPCODES_CMP \
    kOPCODE_TST | \
    kOPCODE_TEQ | \
    kOPCODE_CMP | \
    kOPCODE_CMN
#define CG_OPCODES_ARR \
    kOPCODE_SUB | \
    kOPCODE_RSB | \
    kOPCODE_ADD | \
    kOPCODE_ADC | \
    kOPCODE_SBC | \
    kOPCODE_RSC

#endif // CONSTANTS_H_INCLUDED
