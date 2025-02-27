#ifndef MINER_HPP
#define MINER_HPP

#include "Block.hpp"

class Miner {
public:
    bool mineBlock(Block & block, int difficulty);
};

#endif