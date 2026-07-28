#ifndef OUTPUT_INTERFACE_H
#define OUTPUT_INTERFACE_H

#include <string>
#include <string_view>
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
            virtual void write(std::string_view message) noexcept = 0;

            /**
             * Write a colored string to the console.
             *
             * @param Types::Colors color
             * @param const std::string message
             * @param ... any
             * @return void
             */
            virtual void write(Types::Colors color, std::string_view message) noexcept = 0;

            /**
             * Write a line to the console.
             *
             * @param const std::string line
             * @param ... any
             * @return void
             */
            virtual void writeLine(std::string_view line) noexcept = 0;

            /**
             * Write a colored line to the console.
             *
             * @param Types::Colors color
             * @param const std::string line
             * @param ... any
             * @return void
             */
            virtual void writeLine(Types::Colors color, std::string_view line) noexcept = 0;

            /**
             * Write an error to the console.
             *
             * @param const std::string line
             * @param ... any
             * @return void
             */
            virtual void error(std::string_view line) noexcept = 0;

            /**
             * Write an info to the console.
             *
             * @param const std::string line
             * @param ... any
             * @return void
             */
            virtual void info(std::string_view line) noexcept = 0;

            /**
             * Write a warning to the console.
             *
             * @param const std::string line
             * @param ... any
             * @return void
             */
            virtual void warning(std::string_view line) noexcept = 0;

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