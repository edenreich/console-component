#ifndef APPLICATION_INTERFACE_H
#define APPLICATION_INTERFACE_H

#include "command_interface.h"
#include "../types/exit_code.h"

namespace Console
{
    namespace Interfaces
    {
        /**
         * The Application Interface
         */
        class ApplicationInterface
        {

        public:
            /**
             * Destructor
             */
            virtual ~ApplicationInterface() noexcept = default;

            /**
             * Setter for the application name.
             *
             * @param const std::string & name
             * @return void
             */
            virtual void setApplicationName(const std::string& name) noexcept = 0;

            /**
             * Getter for the application name.
             *
             * @return std::string
             */
            virtual std::string getApplicationName() noexcept = 0;

            /**
             * Setter for the application usage.
             *
             * @param const std::string & usage
             * @return void
             */
            virtual void setApplicationUsage(const std::string& usage) noexcept = 0;

            /**
             * Getter for the application usage.
             *
             * @return std::string
             */
            virtual std::string getApplicationUsage() noexcept = 0;

            /**
             * Setter for the application version.
             *
             * @param const std::string & version
             * @return void
             */
            virtual void setApplicationVersion(const std::string& version) noexcept = 0;

            /**
             * Getter for the application version.
             *
             * @return std::string
             */
            virtual std::string getApplicationVersion() noexcept = 0;

            /**
             * Setter for the application description.
             *
             * @param const std::string & description
             * @return void
             */
            virtual void setApplicationDescription(const std::string& description) noexcept = 0;

            /**
             * Getter for the application description.
             *
             * @return std::string
             */
            virtual std::string getApplicationDescription() noexcept = 0;

            /**
             * Add a command instance to the application.
             *
             * @param CommandInterface * command
             * @return void
             */
            virtual void addCommand(CommandInterface* command) noexcept = 0;

            /**
             * Getter for the available commands,
             * registered by the application.
             *
             * @return Types::Commands
             */
            virtual const Types::Commands& getAvailableCommands() noexcept = 0;

            /**
             * Add a global options.
             *
             * @param const std::string & Option
             * @param const std::string & description
             * @param const std::string & alias
             * @return void
             */
            virtual void addGlobalOption(const std::string& Option, const std::string& description, const std::string& alias) noexcept = 0;

            /**
             * Getter for the available global options.
             *
             * @return Types::AvailableOptions
             */
            virtual Types::AvailableOptions getAvailableGlobalOptions() noexcept = 0;

            /**
             * Set print help to automatically.
             *
             * @param bool yes
             * @return void
             */
            virtual void setAutoPrintHelp(bool yes) noexcept = 0;

            /**
             * Indicates if the application should print
             * the help automatically.
             *
             * @return bool
             */
            virtual bool shouldPrintHelpAutomatically() noexcept = 0;

            /**
             * Getter for the input interface.
             *
             * @return InputInterface*
             */
            virtual InputInterface* getInput() const noexcept = 0;

            /**
             * Getter for the output interface.
             *
             * @return OutputInterface*
             */
            virtual OutputInterface* getOutput() const noexcept = 0;

            /**
             * Guess the requested command.
             *
             * @param const std::string& commandName
             * @return std::string
             */
            virtual std::string guessCommand(const std::string& commandName) noexcept = 0;

            /**
             * Run the console application.
             *
             * @return ExitCode
             */
            [[nodiscard]] virtual ExitCode run() noexcept = 0;
        };
    }
}

#endif // APPLICATION_INTERFACE_H
