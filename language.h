#ifndef LANGUAGE_H_INCLUDED
#define LANGUAGE_H_INCLUDED

#include <stdint.h>
#include <instruction.h>
#include <language/enumerations.h>
#include <language/parsing.h>
#include <language/constants.h>

struct language_rule
{
    char *name;
    enum instruction_type type;
    enum language_token *syntax;
    char *characters;
    uint32_t allowed_opcodes;
};

#endif // LANGUAGE_H_INCLUDED
