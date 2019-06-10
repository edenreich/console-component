#ifndef OUTPUT_INTERFACE_H
#define OUTPUT_INTERFACE_H

#include <string>

namespace Console {

    class ProgressBar;

}

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

        /**
         * Create a progress bar instance.
         * 
         * @param const unsigned int items
         * @return Console::ProgressBar
         */
        virtual ProgressBar * createProgressBar(const unsigned int items) = 0;

    };

}


#endif // OUTPUT_INTERFACE_H