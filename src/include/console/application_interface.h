#ifndef APPLICATION_INTERFACE_H
#define APPLICATION_INTERFACE_H

#include "command.h"
#include "types/exit_code.h"


class IApplication {

public:

    /**
     * Setter for the commands directory path
     * This is where the anotation parser will look
     * for command @name and command @description.
     *
     * @param const std::string & dir
     * @return void
     */
    virtual void setCommandsDirectoryPath(const std::string & dir) = 0;

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
     * @param Command & command
     * @return void
     */
    virtual void addCommand(Command & command) = 0;

   /**
     * Print the help message.
     *
     * @return void
     */
    virtual void printHelp() = 0;

    /**
     * Run the console application.
     * 
     * @return ExitCode
     */
    virtual ExitCode run() = 0;

};


#endif // APPLICATION_INTERFACE_H