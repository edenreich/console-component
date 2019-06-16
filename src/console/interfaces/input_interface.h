#ifndef INPUT_INTERFACE_H
#define INPUT_INTERFACE_H

#include "../types/collections.h"


namespace Console {
    namespace Interfaces {

        /**
         * The Input Interface
         */
        class InputInterface {

        public:

            /**
             * Retrieve an input from the user.
             *
             * @param const std::string & question
             * @return std::string
             */
            virtual std::string ask(const std::string & question) = 0;

            /**
             * Retrieve the parsed options.
             *
             * @return Console::Types::Options
             */
            virtual Console::Types::Options getOptions() = 0;

            /**
             * Setter for the parsed options.
             *
             * @return Console::Types::Options options
             * @return void
             */
            virtual void setOptions(Console::Types::Options options) = 0;

            /**
             * Determine if the -h or --help flag
             * was supplied.
             * 
             * @return bool
             */
            virtual bool wantsHelp() = 0;

            /**
             * Retrieve the option value
             * by given option.
             * 
             * @param const std::string & option
             * @return std::string
             */
            virtual std::string getOption(const std::string & option) = 0;

            /**
             * Retrieve the option value
             * by given option and alias.
             * 
             * @param const std::string & option
             * @param const std::string & alias
             * @return std::string
             */
            virtual std::string getOption(const std::string & option, const std::string & alias) = 0;

        };
    }
}


#endif // INPUT_INTERFACE_H
