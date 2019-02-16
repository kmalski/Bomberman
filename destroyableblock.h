#ifndef DESTROYABLEBLOCK_H
#define DESTROYABLEBLOCK_H

#include "block.h"

class DestroyableBlock : public Block {
public:
    DestroyableBlock() = default;
    ~DestroyableBlock();
};

#endif // DESTROYABLEBLOCK_H
