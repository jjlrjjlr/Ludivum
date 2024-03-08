/*
| Filename: FileReader.h
| Author: Jjlrjjlr
| Date: 2024-03-06
*/

#pragma once

#include <iostream>
#include <fstream>
#include <vector>

#include <ludivum/logger/Logger.h>

namespace ludivum_core{
    class ChunkReader {
        private:
            std::vector<char> charBuffer;
            std::ifstream inFileStream;
            size_t chunkSize;
            size_t readSize;

            logging::Logger logger {"ChunkReader"};

        public:
            ChunkReader(const char* argFilepath, size_t argChunkSize);

            size_t lastReadSize() const;

            const char* readNext();

            bool eof() const;

            virtual ~ChunkReader();
    };

    std::ostream& operator<<(std::ostream &argStream, ludivum_core::ChunkReader &argChunkReader);
}
