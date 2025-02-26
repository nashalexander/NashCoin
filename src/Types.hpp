#ifndef TYPES_HPP
#define TYPES_HPP

#include <vector>

struct Block {
    int timestamp;
    int data;
    std::string magicNumber;
    std::string previousHash;
};

#endif