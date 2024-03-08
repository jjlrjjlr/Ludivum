/*
| Filename: Logger.cpp
| Author: Jjlrjjlr
| Date: 2024-03-08
*/

#include <ludivum/logger/Logger.h>

logging::LogLevels logging::Logger::loggingLevel = logging::LogLevels::NONE;

logging::Logger::Logger(const char* argName) {
    instanceName = argName;
}


void logging::Logger::initLogging(LogLevels argLevel) {
    loggingLevel = argLevel;
}


void logging::Logger::logToCout(const char* argMsg, LogLevels argLevel) const {
    std::cout << LogLevelColors[argLevel] << "[ " << LogLevelNames[argLevel] << " : " << instanceName  \
    << " ] ( " << printTimestamp() << " ) " << argMsg << ANSIResetCode << std::endl;
}

void logging::Logger::logToCerr(const char* argMsg, LogLevels argLevel) const {
    std::cerr << LogLevelColors[argLevel] << "[ " << LogLevelNames[argLevel] << " : " << instanceName  \
    << " ] ( " << printTimestamp() << " ) " << argMsg << ANSIResetCode << std::endl;
}


std::string logging::Logger::printTimestamp() const {
    std::string rStr (20, 0);
    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm *nowTm = std::localtime(&now);

    std::strftime(rStr.data(), 20, "%F %T", nowTm);

    return rStr;
}


void logging::Logger::log(LogLevels argLogLevel, const char* argMsg) const {
    if (argLogLevel >= loggingLevel) {
        if (argLogLevel >= LogLevels::ERROR) {
            logToCerr(argMsg, argLogLevel);
        }
        else {
            logToCout(argMsg, argLogLevel);
        }
    }
}


void logging::Logger::debug(const char* argMsg) const {
    if (LogLevels::DEBUG >= loggingLevel) {
        logToCout(argMsg, LogLevels::DEBUG);
    }
}

void logging::Logger::info(const char* argMsg) const {
    if (LogLevels::INFO >= loggingLevel) {
        logToCout(argMsg, LogLevels::INFO);
    }
}

void logging::Logger::warn(const char* argMsg) const {
    if (LogLevels::WARN >= loggingLevel) {
        logToCout(argMsg, LogLevels::WARN);
    }
}

void logging::Logger::error(const char* argMsg) const {
    if (LogLevels::ERROR >= loggingLevel) {
        logToCerr(argMsg, LogLevels::ERROR);
    }
}

void logging::Logger::fatal(const char* argMsg) const {
    if (LogLevels::FATAL >= loggingLevel) {
        logToCerr(argMsg, LogLevels::FATAL);
    }
}