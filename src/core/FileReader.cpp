/*
| Filename: FileReader.cpp
| Author: Jjlrjjlr
| Date: 2024-03-06
*/

#include <ludivum/core/FileReader.h>

ludivum_core::ChunkReader::ChunkReader(const char* argFilepath, size_t argChunkSize) {
    charBuffer = std::vector<char> (argChunkSize, 0);
    inFileStream.open(argFilepath);

    chunkSize = argChunkSize;

    logger.debug("Chunk reader test");

    if (inFileStream.bad()) {
        std::cerr << "Failed to open file " << argFilepath << std::endl;
    }
}


size_t ludivum_core::ChunkReader::lastReadSize() const {
    return readSize;
}


const char* ludivum_core::ChunkReader::readNext() {
    if (!inFileStream.eof()) {
        inFileStream.read(charBuffer.data(), chunkSize);

        readSize = inFileStream.gcount();
    }

    return charBuffer.data();
}


bool ludivum_core::ChunkReader::eof() const {
    return inFileStream.eof();
}


ludivum_core::ChunkReader::~ChunkReader() {
    inFileStream.close();
}


std::ostream& ludivum_core::operator<<(std::ostream &argStream, ludivum_core::ChunkReader &argChunkReader) {
    argStream << argChunkReader.readNext();

    return argStream;
}