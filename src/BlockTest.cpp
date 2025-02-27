#include "Block.hpp"
#include "BlockChain.hpp"

#include <cassert>

int main() {
    BlockChain blockchain;
    Block block;

    // // Add first block to chain
    // block.hash = "0111";
    // blockchain.addBlock(block);
    // assert(block.hash == blockchain.getLatestBlock().hash);

    // // Add next block to chain
    // block.previousHash = block.hash;
    // block.hash = "0112";
    // blockchain.addBlock(block);
    // assert(block.hash == blockchain.getLatestBlock().hash);

    // // Add a block with a bad previous hash
    // std::string prevHash = block.hash;
    // block.hash = "0113";
    // blockchain.addBlock(block);
    // assert(block.hash != blockchain.getLatestBlock().hash);

    // // Increase difficulty and add block that fails the new value
    // blockchain.updateDifficulty(2);
    // block.previousHash = prevHash;
    // blockchain.addBlock(block);
    // assert(block.hash != blockchain.getLatestBlock().hash);

    // // Match current difficulty
    // block.hash = "0013";
    // blockchain.addBlock(block);
    // assert(block.hash == blockchain.getLatestBlock().hash);

    // Assert chain is always valid
    assert(blockchain.isChainValid());
}