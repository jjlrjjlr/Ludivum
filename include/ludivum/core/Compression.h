/*
| Filename: Compression.h
| Author: Jjlrjjlr
| Date: 2024-03-06
*/

#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <zlib.h>

class GZCompression {
    private:
        gzFile outFile;
        size_t buffSize {4096};

    public:
        GZCompression(const std::string argFilepath);
        GZCompression(const std::string argFilepath, size_t buffSize);

        void GZipCompress(const char* argData, size_t argLength);

        virtual ~GZCompression();
};