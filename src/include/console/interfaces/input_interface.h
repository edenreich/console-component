#ifndef INPUT_INTERFACE_H
#define INPUT_INTERFACE_H

#include "../types/collections.h"

namespace Console
{
    namespace Interfaces
    {
        /**
         * The Input Interface
         */
        class InputInterface
        {

        public:
            /**
             * Destructor
             */
            virtual ~InputInterface() noexcept = default;

            /**
             * Retrieve an input from the user.
             *
             * @param const std::string & question
             * @return std::string
             */
            virtual std::string ask(const std::string& question) noexcept = 0;

            /**
             * Retrieve the parsed options.
             *
             * @return Console::Types::Options
             */
            virtual Console::Types::Options getOptions() noexcept = 0;

            /**
             * Setter for the parsed options.
             *
             * @return Console::Types::Options options
             * @return void
             */
            virtual void setOptions(Console::Types::Options options) noexcept = 0;

            /**
             * Determine if the -h or --help flag
             * was supplied.
             *
             * @return bool
             */
            virtual bool wantsHelp() noexcept = 0;

            /**
             * Retrieve the option value
             * by given option.
             *
             * @param const std::string & option
             * @return std::string
             */
            virtual std::string getOption(const std::string& option) noexcept = 0;

            /**
             * Retrieve the option value
             * by given option and alias.
             *
             * @param const std::string & option
             * @param const std::string & alias
             * @return std::string
             */
            virtual std::string getOption(const std::string& option, const std::string& alias) noexcept = 0;

            /**
             * Retrieve the first positional argument.
             *
             * @return std::string
             */
            virtual std::string getArgument() noexcept = 0;
        };
    }
}

#endif // INPUT_INTERFACE_H
