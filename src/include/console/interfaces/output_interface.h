#ifndef OUTPUT_INTERFACE_H
#define OUTPUT_INTERFACE_H

#include <string>
#include "../types/colors.h"

namespace Console
{
    class ProgressBar;

    namespace Types
    {
        enum class Colors;
    }

    namespace Interfaces
    {
        class CommandInterface;

        /**
         * The Output Interface
         */
        class OutputInterface
        {

        public:
            /**
             * Destructor
             */
            virtual ~OutputInterface() noexcept = default;

            /**
             * Print the help message.
             *
             * @return void
             */
            virtual void printHelp() noexcept = 0;

            /**
             * Print the command help message.
             *
             * @param CommandInterface * command
             * @return void
             */
            virtual void printCommandHelp(CommandInterface* command) noexcept = 0;

            /**
             * Write a string to the console.
             *
             * @param const std::string message
             * @param ... any
             * @return void
             */
            virtual void write(const std::string message, ...) noexcept = 0;

            /**
             * Write a colored string to the console.
             *
             * @param Types::Colors color
             * @param const std::string message
             * @param ... any
             * @return void
             */
            virtual void write(Types::Colors color, const std::string message, ...) noexcept = 0;

            /**
             * Write a line to the console.
             *
             * @param const std::string line
             * @param ... any
             * @return void
             */
            virtual void writeLine(const std::string line, ...) noexcept = 0;

            /**
             * Write a colored line to the console.
             *
             * @param Types::Colors color
             * @param const std::string line
             * @param ... any
             * @return void
             */
            virtual void writeLine(Types::Colors color, const std::string line, ...) noexcept = 0;

            /**
             * Write an error to the console.
             *
             * @param const std::string line
             * @param ... any
             * @return void
             */
            virtual void error(const std::string line, ...) noexcept = 0;

            /**
             * Write an info to the console.
             *
             * @param const std::string line
             * @param ... any
             * @return void
             */
            virtual void info(const std::string line, ...) noexcept = 0;

            /**
             * Write a warning to the console.
             *
             * @param const std::string line
             * @param ... any
             * @return void
             */
            virtual void warning(const std::string line, ...) noexcept = 0;

            /**
             * Create a progress bar instance.
             *
             * @param const unsigned int items
             * @return Console::ProgressBar
             */
            virtual ProgressBar* createProgressBar(const unsigned int items) noexcept = 0;
        };
    }
}

#endif // OUTPUT_INTERFACE_H