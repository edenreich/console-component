#ifndef OUTPUT_H
#define OUTPUT_H

#include "interfaces/output_interface.h"
#include "interfaces/application_interface.h"


namespace Console {

    /**
     * The Output Class
     */
    class Output : public Interfaces::OutputInterface {

    public:

        /**
         * Initialize the application interface.
         * 
         * @param Interfaces::ApplicationInterface * app
         */
        Output(Interfaces::ApplicationInterface * app);

        /**
         * Print the help message.
         *
         * @return void
         */
        void printHelp() override;

        /**
         * Retrieve an input from the user.
         *
         * @param const std::string & line
         * @return void
         */
        void writeLine(const std::string & line) override;

        /**
         * Create a progress bar instance.
         * 
         * @param const unsigned int items
         * @return ProgressBar
         */
        ProgressBar * createProgressBar(const unsigned int items) override;

    private:

        /**
         * Store the application interface.
         * 
         * @var Interfaces::ApplicationInterface * m_app
         */
        Interfaces::ApplicationInterface * m_app;

    };

}


#endif // OUTPUT_H