#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>


namespace utils {


    enum class LogLevel {
        INFO,
        WARNING,
        ERROR
    };


    class Logger {
        public:
            static void log(const std::string& message, LogLevel level = LogLevel::INFO);

            
        private:
            static std::string getLabel(LogLevel level);
            static std::string getColorCode(LogLevel level);
    };
}

#endif
