#ifndef TYPES_HPP
#define TYPES_HPP

#include <string>

class Block {
public:
    std::string getData();
    void setData(std::string data);

    std::string getMagicNumber();
    void setMagicNumber(std::string magicNumber);

    std::string getPreviousHash();
    void setPreviousHash(std::string previousHash);

    std::string getHash();

private:
    std::string data;
    std::string magicNumber;
    std::string previousHash;
    
    // Cached value, invalidated when any other field is set
    std::string hash;
};

#endif