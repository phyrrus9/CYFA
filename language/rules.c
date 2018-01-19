#include <stdlib.h>
#include <language.h>

#define SYN_SRT (enum language_token[]) {
#define SYN_END }

struct language_rule rules[] =
{
    /* category rules */
    { /* CATEGORY RULE for Data Processing (with register) */
        "CAT_DP_REG",       /* .name */
        kINSTRUCTION_DATA,  /* .type */
        SYN_SRT             /* .syntax */
            kTOKEN_MNEMONIC,
            kTOKEN_REGISTER, /* Rd */
            kTOKEN_CHARACTER,
            kTOKEN_REGISTER, /* Rn */
            kTOKEN_CHARACTER,
            kTOKEN_REGISTER  /* Rm */
        SYN_END,
        ",,",              /* .characters */
        C_OPCODES_DP       /* .allowed_opcodes */
    },
    { /* CATEGORY RULE for Data Processing (with offset) */
        "CAT_DP_OFF",       /* .name */
        kINSTRUCTION_DATA,  /* .type */
        SYN_SRT             /* .syntax */
            kTOKEN_MNEMONIC,
            kTOKEN_REGISTER,   /* Rd */
            kTOKEN_CHARACTER,
            kTOKEN_REGISTER,   /* Rn */
            kTOKEN_CHARACTER,
            kTOKEN_EXPRESSION  /* Offset */
        SYN_END,
        ",,",              /* .characters */
        C_OPCODES_DP       /* .allowed_opcodes */
    },
    { /* CATEGORY RULE for Single Data Transfer */
        "CAT_DT",               /* .name */
        kINSTRUCTION_TRANSFER,  /* .type */
        SYN_SRT                 /* .syntax */
            kTOKEN_MNEMONIC,
            kTOKEN_REGISTER,   /* Rd */
            kTOKEN_CHARACTER,
            kTOKEN_REGISTER,   /* Rn */
            kTOKEN_CHARACTER,
            kTOKEN_EXPRESSION  /* offset */
        SYN_END,
        ",,",                  /* .characters */
        C_OPCODES_DT           /* .allowed_opcodes */
    },
    { /* CATEGORY RULE for Branches */
        "CAT_BR",             /* .name */
        kINSTRUCTION_BRANCH,  /* .type */
        SYN_SRT               /* .syntax */
            kTOKEN_MNEMONIC,
            kTOKEN_EXPRESSION /* offset */
        SYN_END,
        NULL,                /* .characters */
        C_OPCODES_BR         /* .allowed_opcodes */
    },
    /* parsing rules */
    /* DP AB Rules */
    { /* ABSOLUTE BASE RULE for Data Processing (logic group) */
        "AB_DP_LGC",        /* .name */
        kINSTRUCTION_DATA,  /* .type */
        SYN_SRT             /* .syntax */
            kTOKEN_OPCODE,
            kTOKEN_REGISTER,
            kTOKEN_CHARACTER,
            kTOKEN_REGISTER,
            kTOKEN_CHARACTER,
            kTOKEN_REGISTER
        SYN_END,
        ",,",               /* .characters */
        CG_OPCODES_LGC      /* .allowed_opcodes */
    },
    { /* ABSOLUTE BASE RULE for Data Processing (comparison group) */
        "AB_DP_CMP",        /* .name */
        kINSTRUCTION_DATA,  /* .type */
        SYN_SRT             /* .syntax */
            kTOKEN_OPCODE,
            kTOKEN_REGISTER,
            kTOKEN_CHARACTER,
            kTOKEN_REGISTER,
            kTOKEN_CHARACTER,
            kTOKEN_REGISTER
        SYN_END,
        ",,",               /* .characters */
        CG_OPCODES_CMP      /* .allowed_opcodes */
    },
    { /* ABSOLUTE BASE RULE for Data Processing (arithmetic group) */
        "AB_DP_ARR",        /* .name */
        kINSTRUCTION_DATA,  /* .type */
        SYN_SRT             /* .syntax */
            kTOKEN_OPCODE,
            kTOKEN_REGISTER,
            kTOKEN_CHARACTER,
            kTOKEN_REGISTER,
            kTOKEN_CHARACTER,
            kTOKEN_REGISTER
        SYN_END,
        ",,",               /* .characters */
        CG_OPCODES_ARR      /* .allowed_opcodes */
    },
    /* DT/BR AB Rules */
    { /* ABSOLUTE BASE RULE for Single Data Transfer */
        "AB_DT",                    /* .name */
        kINSTRUCTION_TRANSFER,      /* .type */
        SYN_SRT                     /* .syntax */
            kTOKEN_OPCODE,
            kTOKEN_REGISTER,
            kTOKEN_CHARACTER,
            kTOKEN_REGISTER,
            kTOKEN_CHARACTER,
            kTOKEN_CONSTANT
        SYN_END,
        ",,",                       /* .characters */
        kOPCODE_LDR | kOPCODE_STR   /* .allowed_opcodes */
    },
    { /* ABSOLUTE BASE RULE for Branches */
        "AB_BR",                /* .name */
        kINSTRUCTION_BRANCH,    /* .type */
        SYN_SRT                 /* .syntax */
            kTOKEN_OPCODE,
            kTOKEN_CONSTANT     /* offset */
        SYN_END,
        NULL,                   /* .characters */
        kOPCODE_B | kOPCODE_BL  /* .allowed_opcodes */
    }
};

#undef SYN_END
#undef SYN_SRT
