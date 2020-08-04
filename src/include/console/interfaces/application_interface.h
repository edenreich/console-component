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
            virtual ~ApplicationInterface() { }

            /**
             * Setter for the application name.
             *
             * @param const std::string & name
             * @return void
             */
            virtual void setApplicationName(const std::string& name) = 0;

            /**
             * Getter for the application name.
             *
             * @return std::string
             */
            virtual std::string getApplicationName() = 0;

            /**
             * Setter for the application usage.
             *
             * @param const std::string & usage
             * @return void
             */
            virtual void setApplicationUsage(const std::string& usage) = 0;

            /**
             * Getter for the application usage.
             *
             * @return std::string
             */
            virtual std::string getApplicationUsage() = 0;

            /**
             * Setter for the application version.
             *
             * @param const std::string & version
             * @return void
             */
            virtual void setApplicationVersion(const std::string& version) = 0;

            /**
             * Getter for the application version.
             *
             * @return std::string
             */
            virtual std::string getApplicationVersion() = 0;

            /**
             * Setter for the application description.
             *
             * @param const std::string & description
             * @return void
             */
            virtual void setApplicationDescription(const std::string& description) = 0;

            /**
             * Getter for the application description.
             *
             * @return std::string
             */
            virtual std::string getApplicationDescription() = 0;

            /**
             * Add a command instance to the application.
             *
             * @param CommandInterface * command
             * @return void
             */
            virtual void addCommand(CommandInterface* command) = 0;

            /**
             * Getter for the available commands,
             * registered by the application.
             *
             * @return Types::Commands
             */
            virtual Types::Commands getAvailableCommands() = 0;

            /**
             * Add a global options.
             *
             * @param const std::string & Option
             * @param const std::string & description
             * @param const std::string & alias
             * @return void
             */
            virtual void addGlobalOption(const std::string& Option, const std::string& description, const std::string& alias) = 0;

            /**
             * Getter for the available global options.
             *
             * @return Types::AvailableOptions
             */
            virtual Types::AvailableOptions getAvailableGlobalOptions() = 0;

            /**
             * Set print help to automatically.
             *
             * @param bool yes
             * @return void
             */
            virtual void setAutoPrintHelp(bool yes) = 0;

            /**
             * Indicates if the application should print
             * the help automatically.
             *
             * @return bool
             */
            virtual bool shouldPrintHelpAutomatically() = 0;

            /**
             * Getter for the input interface.
             *
             * @return InputInterface*
             */
            virtual InputInterface* getInput() const = 0;

            /**
             * Getter for the output interface.
             *
             * @return OutputInterface*
             */
            virtual OutputInterface* getOutput() const = 0;

            /**
             * Guess the requested command.
             *
             * @param std::string commandName
             * @return std::string
             */
            virtual std::string guessCommand(std::string commandName) = 0;

            /**
             * Run the console application.
             *
             * @return ExitCode
             */
            virtual ExitCode run() = 0;
        };
    }
}

#endif // APPLICATION_INTERFACE_H
