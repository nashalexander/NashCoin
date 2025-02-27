#ifndef BLOCK_CHAIN_HPP
#define BLOCK_CHAIN_HPP

#include "Block.hpp"

#include <vector>

class BlockChain {
    public:
        void updateDifficulty(int difficulty);
        int getDifficulty() const;

        void addBlock(Block newBlock);

        bool isChainValid();

        Block & getLatestBlock();

    private:
        std::vector<Block> chain;
        int lastValidBlock = 0; // cache the value
        int difficulty = 1;

};

#endif