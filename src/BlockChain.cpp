#include "BlockChain.hpp"

void BlockChain::updateDifficulty(int difficulty) {
    this->difficulty = difficulty;
}

void BlockChain::addBlock(Block newBlock) {
    if(chain.size() > 0 && newBlock.getPreviousHash() != getLatestBlock().getHash()) {
        return;
    }
    for(int i = 0 ; i < difficulty; i++) {
        if(newBlock.getHash()[i] != '0') {
            // Invalid block difficulty
            return;
        }
    }
    chain.push_back(newBlock);
}

bool BlockChain::isChainValid() {
    for(int i = lastValidBlock + 1; i < chain.size(); i++) {
        Block currentBlock = chain[i];
        Block previousBlock = chain[i - 1];

        if(currentBlock.getPreviousHash() != previousBlock.getHash()) {
            return false;
        }
        else {
            lastValidBlock = i;
        }
    }
    return true;
}

Block & BlockChain::getLatestBlock() {
    return chain.back();
}
