#include "Block.hpp"

#include <openssl/sha.h>


std::string Block::getData() {
    return data;
}

void Block::setData(std::string data) {
    this->data = data;
    hash = "";
}

std::string Block::getMagicNumber() {
    return magicNumber;
}

void Block::setMagicNumber(std::string magicNumber) {
    this->magicNumber = magicNumber;
    hash = "";
}

std::string Block::getPreviousHash() {
    return previousHash;
}

void Block::setPreviousHash(std::string previousHash) {
    this->previousHash = previousHash;
    hash = "";
}

std::string Block::getHash() {
    if(!hash.empty()) {
        return hash;
    }
    
    std::string input = data + magicNumber + previousHash;
    unsigned char hashBuffer[SHA256_DIGEST_LENGTH];
    
    SHA256(reinterpret_cast<const unsigned char*>(input.c_str()), input.size(), hashBuffer);
    hash = std::string(reinterpret_cast<char*>(hashBuffer), SHA256_DIGEST_LENGTH);

    return hash;
}
