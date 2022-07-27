#ifndef CAESARFILEENCRYPTION_FILEDATA_H
#define CAESARFILEENCRYPTION_FILEDATA_H

#include <vector>
#include <string>
#include <fstream>
#include "Key.h"


class FileData {
private:
    std::vector<char> mData{};
    Key mKeyFile{};

public:
    explicit FileData(const std::string& path)
    {
        std::ifstream is{ path, std::ios_base::binary };
        char curChar{};
        long fileSize{ 0 };
        while (is) {
            is.get(curChar);
            mData.push_back(curChar);
            ++fileSize;
        }
        mKeyFile = Key(fileSize);
        is.close();
    }

    FileData(const std::string& path, const Key& keyFile)
    {
        std::ifstream is{ path, std::ios_base::binary };
        char curChar{};
        while (is) {
            is.get(curChar);
            mData.push_back(curChar);
        }
        mKeyFile = keyFile;
        is.close();
    }

    std::vector<char> encrypt();
    std::vector<char> decrypt();
    std::string exportKey();
};


#endif //CAESARFILEENCRYPTION_FILEDATA_H
