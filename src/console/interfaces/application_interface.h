#ifndef APPLICATION_INTERFACE_H
#define APPLICATION_INTERFACE_H

#include "command_interface.h"
#include "../types/exit_code.h"


namespace Console::Interfaces {

    /**
     * The Application Interface
     */
	class ApplicationInterface {

	public:

		/**
		 * Setter for the application name.
		 *
		 * @param const std::string & name
		 * @return void
		 */
		virtual void setApplicationName(const std::string & name) = 0;

		/**
		 * Setter for the application usage.
		 *
		 * @param const std::string & usage
		 * @return void
		 */
		virtual void setApplicationUsage(const std::string & usage) = 0;

		/**
		 * Setter for the application version.
		 *
		 * @param const std::string & version
		 * @return void
		 */
		virtual void setApplicationVersion(const std::string & version) = 0;

		/**
		 * Setter for the application description.
		 *
		 * @param const std::string & description
		 * @return void
		 */
		virtual void setApplicationDescription(const std::string & description) = 0;

		/**
		 * Add a command instance to the application.
		 *
		 * @param CommandInterface * command
		 * @return void
		 */
		virtual void addCommand(CommandInterface * command) = 0;

        /**
		 * Print the help message.
		 *
		 * @return void
		 */
		virtual void printHelp() = 0;

        /**
		 * Set print help to automatically.
		 *
		 * @param bool yes
		 * @return void
		 */
		virtual void setAutoPrintHelp(bool yes) = 0;

		/**
		 * Run the console application.
		 *
		 * @return ExitCode
		 */
		virtual ExitCode run() = 0;

	};

}


#endif // APPLICATION_INTERFACE_H
