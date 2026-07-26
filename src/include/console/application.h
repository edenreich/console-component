#ifndef APPLICATION_H
#define APPLICATION_H

#include "types/collections.h"
#include "interfaces/application_interface.h"
#include "interfaces/output_interface.h"
#include "interfaces/input_interface.h"

#include <memory>

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
        Application(int& argc, char** argv) noexcept;

        /**
         * Setter for the application name.
         *
         * @param const std::string & name
         * @return void
         */
        void setApplicationName(const std::string& name) noexcept override;

        /**
         * Getter for the application name.
         *
         * @return std::string
         */
        std::string getApplicationName() noexcept override;

        /**
         * Setter for the application usage.
         *
         * @param const std::string & usage
         * @return void
         */
        void setApplicationUsage(const std::string& usage) noexcept override;

        /**
         * Getter for the application usage.
         *
         * @return std::string
         */
        std::string getApplicationUsage() noexcept override;

        /**
         * Setter for the application version.
         *
         * @param const std::string & version
         * @return void
         */
        void setApplicationVersion(const std::string& version) noexcept override;

        /**
         * Getter for the application version.
         *
         * @return std::string
         */
        std::string getApplicationVersion() noexcept override;

        /**
         * Setter for the application description.
         *
         * @param const std::string & description
         * @return void
         */
        void setApplicationDescription(const std::string& description) noexcept override;

        /**
         * Getter for the application description.
         *
         * @return std::string
         */
        std::string getApplicationDescription() noexcept override;

        /**
         * Add a command instance to the application.
         *
         * @param CommandInterface * command
         * @return void
         */
        void addCommand(Interfaces::CommandInterface* command) noexcept override;

        /**
         * Getter for the available commands,
         * registered by the application.
         *
         * @return Types::Commands
         */
        const Types::Commands& getAvailableCommands() noexcept override;

        /**
         * Add a command instance to the application.
         *
         * @param const std::string & Option
         * @param const std::string & description
         * @param const std::string & alias
         * @return void
         */
        void addGlobalOption(const std::string& Option, const std::string& description, const std::string& alias) noexcept override;

        /**
         * Getter for the available global options.
         *
         * @return Types::AvailableOptions
         */
        Types::AvailableOptions getAvailableGlobalOptions() noexcept override;

        /**
         * Set print help to automatically.
         *
         * @param bool yes
         * @return void
         */
        void setAutoPrintHelp(bool yes) noexcept override;

        /**
         * Indicates if the application should print
         * the help automatically.
         *
         * @return bool
         */
        bool shouldPrintHelpAutomatically() noexcept override;

        /**
         * Getter for the input interface.
         *
         * @return Interfaces::InputInterface*
         */
        Interfaces::InputInterface* getInput() const noexcept override;

        /**
         * Getter for the output interface.
         *
         * @return Interfaces::OutputInterface*
         */
        Interfaces::OutputInterface* getOutput() const noexcept override;

        /**
         * Guess the requested command.
         *
         * @param const std::string& commandName
         * @return std::string
         */
        std::string guessCommand(const std::string& commandName) noexcept override;

        /**
         * Run the console application.
         *
         * @return ExitCode
         */
        [[nodiscard]] ExitCode run() noexcept override;

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
         * @var std::unique_ptr<Interfaces::OutputInterface> m_output
         */
        std::unique_ptr<Interfaces::OutputInterface> m_output;

        /**
         * Store the input interface.
         *
         * @var std::unique_ptr<Interfaces::InputInterface> m_input
         */
        std::unique_ptr<Interfaces::InputInterface> m_input;
    };
}

#endif // APPLICATION_H