#include <vector>
#include <iostream>
#include "FileData.h"

std::vector<char> FileData::encrypt() {
    long shiftValue = mKeyFile.shiftValue;
    if (shiftValue < 0) {
        shiftValue *= -1;
    }
    long mDataSize{ static_cast<long>(mData.size()) };
    shiftValue %= mDataSize;
    std::vector<char> encryptedData(mDataSize);
    for (long i{ 0 }; i < mDataSize; ++i) {
        encryptedData.at(i) = mData.at((i + shiftValue) % mDataSize);
    }
    return encryptedData;
}

std::vector<char> FileData::decrypt() {
    long shiftValue = mKeyFile.shiftValue;
    if (shiftValue < 0) {
        shiftValue *= -1;
    }
    long mDataSize{ static_cast<long>(mData.size()) };
    shiftValue %= mDataSize;
    std::vector<char> decryptedData(mDataSize);
    for (long i{ 0 }; i < mDataSize; ++i) {
        decryptedData.at((i + shiftValue) % mDataSize) = mData.at(i);
    }
    return decryptedData;
}

std::string FileData::exportKey() {
    return std::to_string(mKeyFile.shiftValue);
}
