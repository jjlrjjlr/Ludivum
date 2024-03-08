/*
| Filename: RomContainer.cpp
| Author: Jjlrjjlr
| Date: 2024-03-05
*/

#include <ludivum/core/RomContainer.h>


ludivum_core::RomContainer::RomContainer() {

}


std::string ludivum_core::RomContainer::encrpyt(const char* argData) {

    switch (cipherType) {
        case CipherType::AES:
            break;

        case CipherType::SERPENT:
            break;

        case CipherType::TWOFISH:
            break;

        default:
            return std::string{argData};
    }
}


std::string ludivum_core::RomContainer::getFilename() const {
    return fileName;
}

size_t ludivum_core::RomContainer::getFileSize() const {
    return fileSize;
}

ludivum_core::ConsoleType ludivum_core::RomContainer::getConsoleType() const {
    return consoleType;
}

ludivum_core::HashType ludivum_core::RomContainer::getHashType() const {
    return hashType;
}

ludivum_core::CipherType ludivum_core::RomContainer::getCipherType() const {
    return cipherType;
}


void ludivum_core::RomContainer::setFilename(const std::string argFilename) {
    fileName = argFilename;
}

void ludivum_core::RomContainer::setFilename(const char* argFilename) {
    fileName = argFilename;
}

void ludivum_core::RomContainer::setFileSize(const size_t argSize) {
    fileSize = argSize;
}

void ludivum_core::RomContainer::setConsoleType(const ludivum_core::ConsoleType argConsole) {
    consoleType = argConsole;
}

void ludivum_core::RomContainer::setHashType(const ludivum_core::HashType argHashType) {
    hashType = argHashType;
}

void ludivum_core::RomContainer::setCipherType(const ludivum_core::CipherType argCipherType) {
    cipherType = argCipherType;
}


void ludivum_core::RomContainer::serialize(const std::string argFilePath) {
    std::ofstream fileStream;
    fileStream.open(argFilePath, std::ios::binary);

    fileStream << "LUDIVUM" << "0.0.1" << '\x1E'\
        << ((u_int8_t) ludivum_util::minimum(fileName.length(), 255)) << fileName.substr(0, ludivum_util::minimum(fileName.length(), 255)) << '\x1E'\
        << (u_int8_t) consoleType << (u_int8_t) hashType << (u_int8_t) cipherType << '\x1E';

    fileStream.flush();
    fileStream.close();

    
}