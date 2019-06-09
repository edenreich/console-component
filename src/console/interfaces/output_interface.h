#ifndef OUTPUT_INTERFACE_H
#define OUTPUT_INTERFACE_H

#include <string>


namespace Console::Interfaces {

    /**
     * The Output Interface
     */
    class OutputInterface {

    public:

        /**
         * Retrieve an input from the user.
         *
         * @param const std::string & line
         * @return void
         */
        virtual void writeLine(const std::string & line) = 0;

    };

}


#endif // OUTPUT_INTERFACE_H