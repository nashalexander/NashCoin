#include "Block.hpp"
#include <climits>

bool Block::mineBlock() {
    for(int i = 0; i < INT_MAX; i++) {
        setNonce(i);

        for(int j = 0; j < dataBlock.difficulty; j++) {
            if(getHash()[j] != '0') {
                break;
            }
            else if(j == dataBlock.difficulty - 1) {
                return true;
            }
        }
    }
    return false;
}

int Block::getData() const {
    return dataBlock.data;
}

void Block::setData(int data) {
    dataBlock.data = data;
    hash = "";
}

int Block::getNonce() const {
    return dataBlock.nonce;
}

void Block::setNonce(int nonce) {
    dataBlock.nonce = nonce;
    hash = "";
}

int Block::getDifficulty() const {
    return dataBlock.difficulty;
}

void Block::setDifficulty(int difficulty) {
    dataBlock.difficulty = difficulty;
    hash = "";
}

std::string Block::getPreviousHash() const {
    return std::string(dataBlock.previousHash, SHA256_DIGEST_LENGTH);
}

void Block::setPreviousHash(std::string previousHash) {
    dataBlock.previousHash = previousHash.c_str();
    hash = "";
}

std::string Block::getHash() {
    if(!hash.empty()) {
        return hash;
    }

    unsigned char hashBuffer[SHA256_DIGEST_LENGTH];
    SHA256(dataBlock, sizeof(dataBlock), hashBuffer);
    hash = std::string(reinterpret_cast<char*>(hashBuffer), SHA256_DIGEST_LENGTH);

    return hash;
}
