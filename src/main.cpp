#include <iostream>
#include <fstream>
#include <string>
#include <memory>

#include "Utility.h"
#include "Key.h"
#include "FileData.h"

#define DECRYPTION_MODE 3
#define ENCRYPTION_MODE 2

int main(int argc, char** argv) {
    std::unique_ptr<Key> keyPtr;
    std::unique_ptr<FileData> fileDataPtr;
    switch (argc) {
    case DECRYPTION_MODE:
        std::cout << "Mode       : Decryption\n";
        std::cout << "File path  : " << argv[1] << '\n';
        std::cout << "Key path   : " << argv[2] << '\n';
        keyPtr = std::make_unique<Key>(static_cast<std::string>(argv[2]));
        fileDataPtr = std::make_unique<FileData>(argv[1], *keyPtr);
        break;
    case ENCRYPTION_MODE:
        std::cout << "Mode       : Encryption\n";
        std::cout << "File path  : " << argv[1] << '\n';
        std::cout << "Key path   : " << Utility::getFileName(argv[1]) << ".key\n";
        keyPtr = std::make_unique<Key>();
        fileDataPtr = std::make_unique<FileData>(static_cast<std::string>(argv[1]), *keyPtr);
        break;
    default:
        std::cerr << "Invalid arguments." << std::endl;
    }
    switch (argc) {
        case DECRYPTION_MODE: {
            std::ofstream decryptedFile{Utility::getFileName(argv[1])
                                        + "decrypted"
                                        + Utility::getFileExtension(argv[1]),
                                        std::ios_base::binary};
            std::vector<char> decryptedData{fileDataPtr->decrypt()};
            for (char curChar: decryptedData) {
                decryptedFile << curChar;
            }
            decryptedFile.close();
            std::cout << "Decryption complete." << std::endl;
            break;
        }
        case ENCRYPTION_MODE: {
            std::ofstream encryptedFile{Utility::getFileName(argv[1])
                                        + "encrypted"
                                        + Utility::getFileExtension(argv[1]),
                                        std::ios_base::binary};
            std::ofstream keyFile{Utility::getFileName(argv[1]) + ".key"};
            std::vector<char> encryptedData{ fileDataPtr->encrypt() };
            for (char curChar: encryptedData) {
                encryptedFile << curChar;
            }
            keyFile << fileDataPtr->exportKey();
            encryptedFile.close();
            keyFile.close();
            break;
            std::cout << "Encryption complete." << std::endl;
        }
        default:
            std::cerr << "Invalid arguments." << std::endl;
    }
}
