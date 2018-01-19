#ifndef PARSING_H_INCLUDED
#define PARSING_H_INCLUDED

struct language_parsing_register
{
    char       *name;
    uint8_t     value : 4; // register number
};

struct language_parsing_opcode
{
    char                   *name;
    enum language_opcode    value; /* DO NOT LOR THESE! */
};

struct language_parsing_condition
{
    char                       *name;
    enum instruction_condition  value;
};

struct language_parsing_mnemonic
{
    uint32_t opcode     : 27;
    uint8_t condition   : 4;
    uint8_t setflags    : 1;
};

#endif // PARSING_H_INCLUDED
