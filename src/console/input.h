#ifndef INPUT_H
#define INPUT_H

#include "interfaces/input_interface.h"


namespace Console {

    /**
     * The Input Class
     */
    class Input : public Interfaces::InputInterface {

    public:

        /**
         * Initialize the options
         * 
         * @param Types::Options options
         */
        Input(Types::Options options);

        /**
         * Retrieve an input from the user.
         *
         * @param const std::string & question
         * @return std::string
         */
        std::string ask(const std::string & question) override;

        /**
         * Retrieve the parsed options.
         *
         * @return Options
         */
        Types::Options getOptions();

    private:

        /**
         * Store the options.
         * 
         * @var Options options
         */
        Types::Options m_options;

    };

}


#endif // INPUT_H
