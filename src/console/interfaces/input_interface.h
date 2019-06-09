#ifndef INPUT_INTERFACE_H
#define INPUT_INTERFACE_H

#include "../types/collections.h"


namespace Console::Interfaces {

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
         * @return Options
         */
        virtual Console::Types::Options getOptions() = 0;

    };

}


#endif // INPUT_INTERFACE_H
