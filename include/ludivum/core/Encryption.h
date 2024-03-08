/*
| Filename: Encryption.h
| Author: Jjlrjjlr
| Date: 2024-03-06
*/

#pragma once

#include <gcrypt.h>
#include <iostream>
#include <vector>

namespace ludivum_core {
    class EncryptionHandler {
        private:
            std::string encryptData(const char* argData, const size_t argDataLength, const char* argKey, size_t argCipher);
            std::string decryptData(const char* argData, const size_t argDataLength, const char* argKey, size_t argCipher);

        public:
            EncryptionHandler();

            std::string encryptSerpent(const char* argData, const size_t argDataLength, const char* argKey);
            std::string decryptSerpent(const char* argData, const size_t argDataLength, const char* argKey);

            std::string encryptTwoFish(const char* argData, const size_t argDataLength, const char* argKey);
            std::string decryptTwoFish(const char* argData, const size_t argDataLength, const char* argKey);
    };
}