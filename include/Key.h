#ifndef CAESARFILEENCRYPTION_KEY_H
#define CAESARFILEENCRYPTION_KEY_H


#include <string>
#include <fstream>
#include <random>

#define KEY_SEED_LOWER_BOUND 256
#define KEY_SEED_UPPER_BOUND 1024

struct Key {
    long shiftValue{};

    // Creates a new, random key for encryption.
    Key()
    {
        std::random_device rd;
        std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd(), };
        std::mt19937 mt{ ss };
        std::uniform_int_distribution<long> dieFileSize{ KEY_SEED_LOWER_BOUND, KEY_SEED_UPPER_BOUND };
        shiftValue = dieFileSize(mt);
    }

    // Reads in a shiftValue from an existing key file.
    Key(const std::string& path) {
        std::ifstream is{ path };
        std::string shiftString{};
        std::getline(is, shiftString);
        shiftValue = std::stoi(shiftString);
        is.close();
    }
};


#endif //CAESARFILEENCRYPTION_KEY_H
