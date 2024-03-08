/*
| Filename: Test.cpp
| Author: Jjlrjjlr
| Date: 2024-03-05
*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <zlib.h>

#include <ludivum/core/Compression.h>
#include <ludivum/core/Encryption.h>
#include <ludivum/core/FileReader.h>
#include <ludivum/logger/Logger.h>
#include <ludivum/core/RomContainer.h>
#include <ludivum/core/Utilities.h>

int main(int argc, char* argv[]) {
    logging::Logger::initLogging(logging::DEBUG);
    logging::Logger log {"Test.cpp"};

    ludivum_core::RomContainer container;
    container.setFilename("Test.txt");
    container.setFileSize(97);
    container.setConsoleType(ludivum_core::ConsoleType::GB);
    container.setCipherType(ludivum_core::CipherType::SERPENT);
    container.setHashType(ludivum_core::HashType::SHA256);

    if (argc == 2) {
        container.serialize(argv[1]);
    }

    GZCompression gzOut {"./data/comp_test"};
    ludivum_core::ChunkReader reader {"./data/Test.txt", 512};

    while (!reader.eof()) {
        const char* data = reader.readNext();
        gzOut.GZipCompress(data, reader.lastReadSize());
    }

    ludivum_core::EncryptionHandler encrypt;
    std::string testData = ludivum_util::padStringToMultiple("This is a test...aefkrcb1123123gtrbetydrhydrt", 16);
    std::string encryptedData = encrypt.encryptSerpent(testData.c_str(), testData.length(), "This is a test");
    std::string decryptedData = encrypt.decryptSerpent(encryptedData.c_str(), encryptedData.length(), "This is a test");
    
    std::cout << std::hex << encryptedData << std::endl << std::endl;
    std::cout << std::hex << decryptedData << std::endl;

    std::cout << std::dec << encryptedData.length() << std::endl;
    std::cout << std::dec << decryptedData.length() << std::endl;

    log.debug("Debug test");
    log.info("Info test");
    log.warn("Warn test");
    log.error("Error test");
    log.fatal("Fatal test");

    return 0;
}
