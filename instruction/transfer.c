#include <instruction/transfer.h>

void instruction_init_transfer(struct instruction_transfer *encode)
{
    encode->hard = 0x1; // hard code to 0b1 per arm spec
    /* set bits for this assembler's spec */
    encode->I = 0x0;
    encode->P = 0x1;
    encode->B = 0x0;
    encode->W = 0x1;
}
