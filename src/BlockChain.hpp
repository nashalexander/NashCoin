#ifndef BLOCK_CHAIN_HPP
#define BLOCK_CHAIN_HPP

#include "Types.hpp"

class BlockChain {
    public:
        void updateDifficulty(int difficulty);

        void addBlock(Block newBlock);

        bool isChainValid();

        Block & getLatestBlock();

    private:
        std::vector<Block> chain;
        int lastValidBlock = 0; // cache the value
        int difficulty = 1;

};

#ifndef