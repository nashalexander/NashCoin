#include "Block.hpp"
#include "BlockChain.hpp"

#include <cassert>

int main() {
    BlockChain blockchain;
    Block block;

    blockchain.updateDifficulty(2);
    block.setDifficulty(blockchain.getDifficulty());

    // Add first block to chain
    block.setData(1);
    bool successful = block.mineBlock();
    if(successful) {
        blockchain.addBlock(block);
    }
    assert(block.getData() == blockchain.getLatestBlock().getData());
    assert(blockchain.isChainValid());

    // Add next block to chain
    block.setData(2);
    block.setPreviousHash(blockchain.getLatestBlock().getHash());
    successful = block.mineBlock();
    if(successful) {
        blockchain.addBlock(block);
    }
    assert(block.getData() == blockchain.getLatestBlock().getData());
    assert(blockchain.isChainValid());

    // Add a block with a bad previous hash
    block.setPreviousHash("badHash");
    successful = block.mineBlock();
    if(successful) {
        blockchain.addBlock(block);
    }
    assert(block.getHash() != blockchain.getLatestBlock().getHash());
    assert(blockchain.isChainValid());
 
}