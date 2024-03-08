/*
| Filename: Compression.cpp
| Author: Jjlrjjlr
| Date: 2024-03-06
*/

#include <ludivum/core/Compression.h>

GZCompression::GZCompression(const std::string argFilepath) {
    outFile = gzopen(argFilepath.c_str(), "wb");
    gzbuffer(outFile, buffSize);
}

GZCompression::GZCompression(const std::string argFilepath, size_t argBuffSize) {
    outFile = gzopen(argFilepath.c_str(), "wb");
    buffSize = argBuffSize;
    gzbuffer(outFile, buffSize);
}


void GZCompression::GZipCompress(const char* argData, size_t argLength) {
    gzwrite(outFile, argData, argLength);
    gzflush(outFile, Z_FULL_FLUSH);
}


GZCompression::~GZCompression() {
    gzclose(outFile);
}