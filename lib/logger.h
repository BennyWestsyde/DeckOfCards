//
// Created by Bennett Westfall on 10/18/23.
//

#ifndef DECKOFCARDS_LOGGER_H
#define DECKOFCARDS_LOGGER_H


#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

class Logger {
public:
    enum LogLevel {
        INFO = 0,
        DEBUG = 1,
        WARNING = 2,
        ERROR = 3,
        FATAL = 4
    };

    explicit Logger() {
        filename = "log" + getCurrentTime() + ".txt";
        logStream.open(filename, std::ios::out | std::ios::app);
        if (!logStream) {
            std::cerr << "Failed to open log file: " << filename << std::endl;
        }
    }

    explicit Logger(const std::string& filename) : filename(filename) {
        logStream.open(filename, std::ios::out | std::ios::app);
        if (!logStream) {
            std::cerr << "Failed to open log file: " << filename << std::endl;
        }
    }

    ~Logger() {
        if (logStream) {
            logStream.close();
        }
    }

    void log(const std::string& message, LogLevel level, const char* file, int line) {
        if (!logStream) {
            return;
        }

        std::string levelStr;
        switch (level) {
            case INFO:
                levelStr = "INFO";
                break;
            case DEBUG:
                levelStr = "DEBUG";
                break;
            case WARNING:
                levelStr = "WARNING";
                break;
            case ERROR:
                levelStr = "ERROR";
                break;
            case FATAL:
                levelStr = "FATAL";
                break;
        }
        std::string timestamp = getCurrentTime();
        logStream << "[" << timestamp << "][" << levelStr << "][" << file << ":" << line << "] " << message << std::endl;
    }

private:
    std::string getCurrentTime() {
        std::time_t now = std::time(nullptr);
        char buffer[100];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
        return std::string(buffer);
    }

    std::string filename;
    std::ofstream logStream;
};

Logger logger = Logger();

#define LOG(level, message) logger.log(message, level, __FILE__, __LINE__)
#define DEBUG(message) logger.log(message, Logger::DEBUG, __FILE__, __LINE__)
#define INFO(message) logger.log(message, Logger::INFO, __FILE__, __LINE__)
#define WARNING(message) logger.log(message, Logger::WARNING, __FILE__, __LINE__)
#define ERROR(message) logger.log(message, Logger::ERROR, __FILE__, __LINE__)
#define FATAL(message) logger.log(message, Logger::FATAL, __FILE__, __LINE__)




#endif //DECKOFCARDS_LOGGER_H
