#include "Utility.h"

std::string Utility::getFileName(char *fileName) {
    std::string fileNameStr(fileName);
    return fileNameStr.substr(0, fileNameStr.find_first_of('.'));
}

std::string Utility::getFileExtension(char *fileName) {
    std::string fileNameStr(fileName);
    return fileNameStr.substr(fileNameStr.find_first_of('.'), fileNameStr.size() - 1);
}
