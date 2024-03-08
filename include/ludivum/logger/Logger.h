/*
| Filename: Logger.h
| Author: Jjlrjjlr
| Date: 2024-03-07
*/

#pragma once

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <unordered_map>

namespace logging {
    enum LogLevels {
        DEBUG = 0,
        INFO,
        WARN,
        ERROR,
        FATAL,
        NONE
    };

    inline const char* LogLevelNames[6] {
        {"DEBUG"},
        {"INFO"},
        {"WARN"},
        {"ERROR"},
        {"FATAL"},
        {"NONE"}
    };

    inline const char* LogLevelColors[6] {
        {"\e[1;90m"},
        {"\e[1;37m"},
        {"\e[1;33m"},
        {"\e[1;91m"},
        {"\e[2;31m"},
        {"\e[0m"}
    };

    inline const char* ANSIResetCode {"\e[0m"};

    class Logger {
        private:
            static LogLevels loggingLevel;

            const char* instanceName;

            void logToCout(const char* argMsg, LogLevels argLevel) const;
            void logToCerr(const char* argMsg, LogLevels argLevel) const;

            std::string printTimestamp() const;

        public:
            Logger(const char* argName);
            Logger(const Logger& argLogger) = delete;

            static void initLogging(LogLevels argLevel);

            void log(LogLevels argLevel, const char* argMsg) const;

            void debug(const char* argMsg) const;
            void info(const char* argMsg) const;
            void warn(const char* argMsg) const;
            void error(const char* argMsg) const;
            void fatal(const char* argMsg) const;
    };
}