#ifndef OUTPUT_H
#define OUTPUT_H

#include "interfaces/output_interface.h"


namespace Console {

    /**
     * The Output Class
     */
    class Output : public Interfaces::OutputInterface {

    public:

        /**
         * Retrieve an input from the user.
         *
         * @param const std::string & line
         * @return void
         */
        void writeLine(const std::string & line) override;

    };

}


#endif // OUTPUT_H