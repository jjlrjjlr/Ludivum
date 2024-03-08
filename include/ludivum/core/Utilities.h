/*
| Filename: Utilities.h
| Author: Jjlrjjlr
| Date: 2024-03-07
*/

#pragma once

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace ludivum_util {
    size_t roundUp(const size_t argValue, const size_t argTargetMultiple);

    std::string padStringToMultiple(const std::string &argInStr, const size_t &argTargetMultiple);

    size_t minimum(const size_t &argA, const size_t &argB);

    std::string toHex(const char* argInput);
}