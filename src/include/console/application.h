#ifndef APPLICATION_H
#define APPLICATION_H

#include "types/collections.h"
#include "interfaces/application_interface.h"
#include "interfaces/output_interface.h"
#include "interfaces/input_interface.h"

namespace Console
{

    /**
     * The Application Class
     */
    class Application : public Interfaces::ApplicationInterface
    {

    public:
        /**
         * - Initialize the arguments count
         * - initialize the arguments values
         *
         * @param int & argc
         * @param char ** argv
         */
        Application(int& argc, char** argv);

        /**
         * Destroy the application.
         */
        virtual ~Application();

        /**
         * Setter for the application name.
         *
         * @param const std::string & name
         * @return void
         */
        void setApplicationName(const std::string& name) override;

        /**
         * Getter for the application name.
         *
         * @return std::string
         */
        std::string getApplicationName() override;

        /**
         * Setter for the application usage.
         *
         * @param const std::string & usage
         * @return void
         */
        void setApplicationUsage(const std::string& usage) override;

        /**
         * Getter for the application usage.
         *
         * @return std::string
         */
        std::string getApplicationUsage() override;

        /**
         * Setter for the application version.
         *
         * @param const std::string & version
         * @return void
         */
        void setApplicationVersion(const std::string& version) override;

        /**
         * Getter for the application version.
         *
         * @return std::string
         */
        std::string getApplicationVersion() override;

        /**
         * Setter for the application description.
         *
         * @param const std::string & description
         * @return void
         */
        void setApplicationDescription(const std::string& description) override;

        /**
         * Getter for the application description.
         *
         * @return std::string
         */
        std::string getApplicationDescription() override;

        /**
         * Add a command instance to the application.
         *
         * @param CommandInterface * command
         * @return void
         */
        void addCommand(Interfaces::CommandInterface* command) override;

        /**
         * Getter for the available commands,
         * registered by the application.
         *
         * @return Types::Commands
         */
        Types::Commands getAvailableCommands() override;

        /**
         * Add a command instance to the application.
         *
         * @param const std::string & Option
         * @param const std::string & description
         * @param const std::string & alias
         * @return void
         */
        void addGlobalOption(const std::string& Option, const std::string& description, const std::string& alias) override;

        /**
         * Getter for the available global options.
         *
         * @return Types::AvailableOptions
         */
        Types::AvailableOptions getAvailableGlobalOptions() override;

        /**
         * Set print help to automatically.
         *
         * @param bool yes
         * @return void
         */
        void setAutoPrintHelp(bool yes) override;

        /**
         * Indicates if the application should print
         * the help automatically.
         *
         * @return bool
         */
        bool shouldPrintHelpAutomatically() override;

        /**
         * Getter for the input interface.
         *
         * @return Interfaces::InputInterface*
         */
        Interfaces::InputInterface* getInput() const override;

        /**
         * Getter for the output interface.
         *
         * @return Interfaces::OutputInterface*
         */
        Interfaces::OutputInterface* getOutput() const override;

        /**
         * Guess the requested command.
         *
         * @param std::string commandName
         * @return std::string
         */
        std::string guessCommand(std::string commandName) override;

        /**
         * Run the console application.
         *
         * @return ExitCode
         */
        ExitCode run() override;

    private:
        /**
         * Store the arguments count.
         *
         * @var int
         */
        int m_argc;

        /**
         * Store the arguments values.
         *
         * @var char** m_argv
         */
        char** m_argv;

        /**
         * Store the name
         * of the application.
         *
         * @var std::string
         */
        std::string m_name;

        /**
         * Store the application
         * usage instructions.
         *
         * @var std::string
         */
        std::string m_usage;

        /**
         * Store the application version.
         *
         * @var std::string
         */
        std::string m_version;

        /**
         * Store the application description.
         *
         * @var std::string
         */
        std::string m_description;

        /**
         * Store the print help flag.
         *
         * @var bool
         */
        bool m_printHelpAutomatically;

        /**
         * Store the available commands.
         *
         * @var Types::Commands
         */
        Types::Commands m_commands;

        /**
         * Store the available options.
         *
         * @var Types::AvailableOptions
         */
        Types::AvailableOptions m_options;

        /**
         * Store the output interface.
         *
         * @var Interfaces::OutputInterface* m_output
         */
        Interfaces::OutputInterface* m_output;

        /**
         * Store the input interface.
         *
         * @var Interfaces::InputInterface* m_input
         */
        Interfaces::InputInterface* m_input;
    };
}

#endif // APPLICATION_H