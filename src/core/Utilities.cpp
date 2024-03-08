/*
| Filename: Utilities.cpp
| Author: Jjlrjjlr
| Date: 2024-03-07
*/

#include <ludivum/core/Utilities.h>

size_t ludivum_util::roundUp(const size_t argValue, const size_t argTargetMultiple) {
    return ((argValue % argTargetMultiple == 0) ? argValue : ((argValue + argTargetMultiple) - (argValue % argTargetMultiple)));
}


std::string ludivum_util::padStringToMultiple(const std::string &argInStr, const size_t &argTargetMultiple) {
    std::string rString;
    rString.resize(roundUp(argInStr.length(), argTargetMultiple));

    std::copy(argInStr.begin(), argInStr.end(), rString.begin());

    return rString;
}


size_t ludivum_util::minimum(const size_t &argA, const size_t &argB) {
    return ((argA < argB) ? argA : argB);
}


std::string ludivum_util::toHex(const char* argInput) {
    std::stringstream rString;

    rString << std::hex << std::setfill('0');

    while (*argInput != '\0') {
        rString << std::hex << std::setw(2) << (0xFF & static_cast<unsigned>(*argInput));
        *argInput++;
    }

    return rString.str();
}