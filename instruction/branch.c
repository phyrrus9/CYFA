#include <instruction/branch.h>

void instruction_init_branch(struct instruction_branch *encode)
{
    encode->hard = 0x5; // hard code 0b101 per ARM spec
}
