#include <stdint.h>
#ifdef _WIN32
#include <Winsock2.h>
#else
#include <arpa/inet.h>
#endif
#include <instruction.h>

/* signatures not defined in this file */
void instruction_init_data(struct instruction_data *);
void instruction_init_transfer(struct instruction_transfer *);
void instruction_init_branch(struct instruction_branch *);
/* signatures for this file (hidden) */
uint32_t instruction_endian(uint32_t);
union instruction_encoder
{
    union instruction source;
    uint32_t destination;
};

void instruction_init(union instruction *encoder, enum instruction_type type)
{
    switch (type)
    {
    case kINSTRUCTION_DATA:
        instruction_init_data(&encoder->DP);
        break;
    case kINSTRUCTION_TRANSFER:
        instruction_init_transfer(&encoder->DT);
        break;
    case kINSTRUCTION_BRANCH:
        instruction_init_branch(&encoder->BR);
        break;
    default: // will allow our undef to go through
        break;
    }
}

uint32_t instruction_endian(uint32_t encode)
{
    if (htonl(encode) == encode) // system is big endian
        return ntohl(encode);
    return encode; // system is little endian
}

uint32_t instruction_encode(union instruction *encode)
{
    union instruction_encoder encoder;
    encoder.source = *encode; // make a copy for translation
    return instruction_endian(encoder.destination); // convert endians and return our integer
}
