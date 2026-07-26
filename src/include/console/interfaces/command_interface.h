#ifndef COMMAND_H
#define COMMAND_H

#include "../types/exit_code.h"
#include "input_interface.h"
#include "output_interface.h"

namespace Console
{
    namespace Interfaces
    {
        /**
         * The Command Interface
         */
        class CommandInterface
        {

        public:
            /**
             * Destructor
             */
            virtual ~CommandInterface() noexcept = default;

            /**
             * Handle the command.
             *
             * @param InputInterface * input
             * @param InputInterface * output
             * @return ExitCode
             */
            [[nodiscard]] virtual ExitCode handle(InputInterface* input, OutputInterface* output) noexcept = 0;

            /**
             * Retrieve the name of the command.
             *
             * @return std::string
             */
            virtual std::string getName() noexcept = 0;

            /**
             * Retrieve the description of the command.
             *
             * @return std::string
             */
            virtual std::string getDescription() noexcept = 0;

            /**
             * Retrieve the command options.
             *
             * @return Types::AvailableOptions
             */
            virtual Types::AvailableOptions getOptions() noexcept = 0;
        };
    }
}

#endif // COMMAND_H
