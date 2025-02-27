#include "Block.hpp"

#include <openssl/sha.h>


int Block::getData() {
    return data;
}

void Block::setData(int data) {
    this->data = data;
    hash = "";
}

int Block::getNonce() {
    return nonce;
}

void Block::setNonce(int nonce) {
    this->nonce = nonce;
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
    
    //TODO: replace with a zero-copy solution
    size_t inputSize = sizeof(data) + sizeof(nonce) + previousHash.size();
    unsigned char * input = new unsigned char(inputSize);
    std::memcpy(input, &data, sizeof(data));
    std::memcpy(input + sizeof(data), &nonce, sizeof(nonce));
    std::memcpy(input + sizeof(data) + sizeof(nonce), previousHash.c_str(), previousHash.size());

    unsigned char hashBuffer[SHA256_DIGEST_LENGTH];

    SHA256(const_cast<const unsigned char*>(input), inputSize, hashBuffer);
    hash = std::string(reinterpret_cast<char*>(hashBuffer), SHA256_DIGEST_LENGTH);

    return hash;
}
