#include "Miner.hpp"

#include <climits>

bool Miner::mineBlock(Block & block, int difficulty) {
    for(int i = 0; i < std::INT_MAX; i++) {
        block.setNonce(i);

        for(int j = 0; j < difficulty; j++) {
            if(block.getHash()[j] != '0') {
                break;
            }
            else if(j == difficulty - 1) {
                return true;
            }
        }
    }

    return false;
}