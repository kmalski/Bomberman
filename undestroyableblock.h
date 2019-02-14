#ifndef UNDESTROYABLEBLOCK_H
#define UNDESTROYABLEBLOCK_H

#include "block.h"

class UnDestroyableBlock : public Block {
public:
    UnDestroyableBlock() = default;
    ~UnDestroyableBlock();
};

#endif // UNDESTROYABLEBLOCK_H
