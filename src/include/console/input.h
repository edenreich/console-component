#ifndef INPUT_H
#define INPUT_H

#include "interfaces/input_interface.h"
#include "interfaces/application_interface.h"

namespace Console
{
    /**
     * The Input Class
     */
    class Input : public Interfaces::InputInterface
    {

    public:
        /**
         * Initialize the application interface.
         *
         * @param Interfaces::ApplicationInterface * app
         */
        Input(Interfaces::ApplicationInterface* app);

        /**
         * Retrieve an input from the user.
         *
         * @param const std::string & question
         * @return std::string
         */
        std::string ask(const std::string& question) override;

        /**
         * Retrieve the parsed options.
         *
         * @return Options
         */
        Types::Options getOptions() override;

        /**
         * Setter for the parsed options.
         *
         * @return Console::Types::Options options
         * @return void
         */
        void setOptions(Console::Types::Options options) override;

        /**
         * Determine if the -h or --help flag
         * was supplied.
         *
         * @return bool
         */
        bool wantsHelp() override;

        /**
         * Retrieve the option value
         * by given option.
         *
         * @param const std::string & option
         * @return std::string
         */
        std::string getOption(const std::string& option) override;

        /**
         * Retrieve the option value
         * by given option and alias.
         *
         * @param const std::string & option
         * @param const std::string & alias
         * @return std::string
         */
        std::string getOption(const std::string& option, const std::string& alias) override;

    private:
        /**
         * Store the options.
         *
         * @var Options options
         */
        Types::Options m_options;

        /**
         * Store the application interface.
         *
         * @var Interfaces::ApplicationInterface * m_app
         */
        Interfaces::ApplicationInterface* m_app;
    };
}

#endif // INPUT_H
