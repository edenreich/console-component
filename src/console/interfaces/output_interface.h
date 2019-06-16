#ifndef OUTPUT_INTERFACE_H
#define OUTPUT_INTERFACE_H

#include <string>
#include "../types/colors.h"


namespace Console {

    class ProgressBar;

    namespace Types {

        enum class Colors;

    }

    namespace Interfaces {

        class CommandInterface;

        /**
         * The Output Interface
         */
        class OutputInterface {

        public:

            /**
             * Print the help message.
             *
             * @return void
             */
            virtual void printHelp() = 0;

            /**
             * Print the command help message.
             *
             * @param CommandInterface * command
             * @return void
             */
            virtual void printCommandHelp(CommandInterface * command) = 0;

            /**
             * Write a string to the console.
             *
             * @param const std::string & line
             * @param Types::Colors color
             * @return void
             */
            virtual void write(const std::string & line, Types::Colors color = Types::Colors::NORMAL) = 0;

            /**
             * Write a line to the console.
             *
             * @param const std::string & line
             * @param Types::Colors color
             * @return void
             */
            virtual void writeLine(const std::string & line, Types::Colors color = Types::Colors::NORMAL) = 0;

            /**
             * Write a line break to the console.
             * 
             * @return void
             */
            virtual void writeLineBreak() = 0;

            /**
             * Write an error to the console.
             *
             * @param const std::string & line
             * @return void
             */
            virtual void error(const std::string & line) = 0;

            /**
             * Write an info to the console.
             *
             * @param const std::string & line
             * @return void
             */
            virtual void info(const std::string & line) = 0;

            /**
             * Write a warning to the console.
             *
             * @param const std::string & line
             * @return void
             */
            virtual void warning(const std::string & line) = 0;

            /**
             * Create a progress bar instance.
             * 
             * @param const unsigned int items
             * @return Console::ProgressBar
             */
            virtual ProgressBar * createProgressBar(const unsigned int items) = 0;

        };
    }
}


#endif // OUTPUT_INTERFACE_H