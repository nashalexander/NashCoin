#ifndef TYPES_HPP
#define TYPES_HPP

#include <string>
#include <openssl/sha.h>

class Block {
public:
    bool mineBlock();

    int getData() const;
    void setData(int data);

    int getNonce() const;
    void setNonce(int nonce);

    int getDifficulty() const;
    void setDifficulty(int difficulty);

    // TODO: fix this string nonsense
    std::string getPreviousHash() const;
    void setPreviousHash(std::string previousHash);

    std::string getHash();

private:
    union {
        struct{
            uint32_t data;
            uint32_t nonce;
            uint32_t difficulty;
            unsigned char previousHash[SHA256_DIGEST_LENGTH];
        };
        unsigned char block[sizeof(uint32_t)*3 + SHA256_DIGEST_LENGTH];
    } dataBlock;

    // Cached value, invalidated when any other field is set
    std::string hash;
};

#endif