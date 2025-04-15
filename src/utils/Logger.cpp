#include "utils/Logger.h"
#include <iostream>


namespace utils {


    void Logger::log(const std::string& message, LogLevel level) {
        std::string label = getLabel(level);
        std::string color = getColorCode(level);
        std::string reset = "\033[0m";

        std::cout << color << '[' << label << ']' << message << reset << '\n';
    }


    std::string Logger::getLabel(LogLevel level) {
        switch (level) {
            case LogLevel::INFO: return "INFO";
            case LogLevel::WARNING: return "WARNING";
            case LogLevel::ERROR: return "ERROR";
            default: return "LOG";
        }
    }
    
    std::string Logger::getColorCode(LogLevel level) {
        switch (level) {
            case LogLevel::INFO: return "\033[32m";   // Verde
            case LogLevel::WARNING: return "\033[33m"; // Amarelo
            case LogLevel::ERROR: return "\033[31m";   // Vermelho
            default: return "\033[0m";
        }
    }
}