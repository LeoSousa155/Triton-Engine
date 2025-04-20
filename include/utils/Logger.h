#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>


namespace utils {

    /** @brief Defines different severity levels for logging messages. */
    enum class LogLevel {
        INFO,       ///< Informational messages.
        WARNING,    ///< Potential issues or non-critical errors.
        ERROR       ///< Critical errors that might prevent normal operation.
    };

    /**
     * @class Logger
     * @brief Provides static methods for logging messages to the console with different severity levels and colors.
     */
    class Logger {
        public:
            /**
             * @brief Logs a message to the standard output stream with a specified level.
             * Prepends a colored label (e.g., "[INFO]", "[WARNING]", "[ERROR]") to the message.
             * @param message The string message to log.
             * @param level The severity level of the message (defaults to INFO).
             */
            static void log(const std::string& message, LogLevel level = LogLevel::INFO);


        private:
            /**
             * @brief Gets the string representation for a given log level (e.g., "INFO").
             * @param level The log level.
             * @return A string label for the level.
             */
            static std::string getLabel(LogLevel level);

            /**
             * @brief Gets the ANSI escape code for coloring the output based on the log level.
             * @param level The log level.
             * @return A string containing the ANSI color code.
             */
            static std::string getColorCode(LogLevel level);
    };
}

#endif
