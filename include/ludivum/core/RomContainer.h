/*
| Filename: RomContainer.h
| Author: Jjlrjjlr
| Date: 2024-03-05
| Description: A container that contains a file header consisting of ROM
|    metadata (console, hash, filesize, etc) as well as the compressed
|    encrypted ROM.
*/

#pragma once

#include <fstream>
#include <gcrypt.h>
#include <string>
#include <zlib.h>

#include "Utilities.h"

namespace ludivum_core {
    enum HashType {
        SHA256 = 8,
        MD5_128,
        BLAKE2B_256
    };

    enum CipherType {
        AES = 16,
        SERPENT,
        TWOFISH,
        NONE
    };

    enum ConsoleType {
        NES = 32,
        SNES,
        N64,
        GB,
        GBC,
        GBA,
        NDS,
        GCN,
        NWII,
        NWIIU,
        NSWITCH,

        PSX = 64,
        PSP,
        PS2,
        PS3
    };

    class RomContainer {
        private:
            std::string fileName;
            size_t fileSize;
            ConsoleType consoleType;
            HashType hashType;
            CipherType cipherType;

            std::string encrpyt(const char* argData);

        public:
            RomContainer();

            std::string getFilename() const;
            size_t getFileSize() const;
            ConsoleType getConsoleType() const;
            HashType getHashType() const;
            CipherType getCipherType() const;

            void setFilename(const std::string argFilename);
            void setFilename(const char* argFilename);
            void setFileSize(const size_t argSize);
            void setConsoleType(const ConsoleType argConsole);
            void setHashType(const HashType argHashType);
            void setCipherType(const CipherType argCipherType);

            void serialize(const std::string argFilePath);
    };
};