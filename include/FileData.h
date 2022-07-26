#ifndef CAESARFILEENCRYPTION_FILEDATA_H
#define CAESARFILEENCRYPTION_FILEDATA_H

#include <vector>
#include <string>
#include <fstream>
#include "Key.h"


class FileData {
private:
    std::vector<char> mData{};
    Key mKeyFile;

public:
    FileData(const std::string& path, Key keyFile) : mKeyFile{ keyFile }
    {
        std::ifstream is{ path, std::ios_base::binary };
        char curChar{};
        while (is) {
            is.get(curChar);
            mData.push_back(curChar);
        }
        is.close();
    }

    std::vector<char> encrypt();
    std::vector<char> decrypt();
    std::string exportKey();
};


#endif //CAESARFILEENCRYPTION_FILEDATA_H
