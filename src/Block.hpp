#ifndef TYPES_HPP
#define TYPES_HPP

#include <string>

class Block {
public:
    int getData();
    void setData(int data);

    int getNonce();
    void setNonce(int nonce);

    std::string getPreviousHash();
    void setPreviousHash(std::string previousHash);

    std::string getHash();

private:
    int data;
    int nonce;
    std::string previousHash;
    
    // Cached value, invalidated when any other field is set
    std::string hash;
};

#endif