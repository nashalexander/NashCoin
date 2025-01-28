#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <vector>

struct Block {
    int timestamp;
    int data;
    std::string previousHash;
    std::string hash;
};

class BlockChain {
    public:
        void updateDifficulty(int difficulty) {
            this->difficulty = difficulty;
        }

        void addBlock(Block newBlock) {
            if(chain.size() > 0 && newBlock.previousHash != getLatestBlock().hash) {
                return;
            }
            for(int i = 0 ; i < difficulty; i++) {
                if(newBlock.hash[i] != '0') {
                    // Invalid block difficulty
                    return;
                }
            }
            chain.push_back(newBlock);
        }

        bool isChainValid() {
            for(int i = lastValidBlock + 1; i < chain.size(); i++) {
                Block currentBlock = chain[i];
                Block previousBlock = chain[i - 1];

                if(currentBlock.previousHash != previousBlock.hash) {
                    return false;
                }
                else {
                    lastValidBlock = i;
                }
            }
            return true;
        }

        Block & getLatestBlock() {
            return chain.back();
        }

    private:
        std::vector<Block> chain;
        int lastValidBlock = 0; // cache the value
        int difficulty = 1;

};

#endif