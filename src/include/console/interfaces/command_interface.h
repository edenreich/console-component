#ifndef COMMAND_H
#define COMMAND_H

#include "../types/exit_code.h"
#include <string>
#include <vector>


class CommandInterface {

public:

    /**
     * Handle the command.
     *
     * @param std::vector<std::string> options
     * @return ExitCode
     */
    virtual ExitCode handle(std::vector<std::string> options) = 0;

    /**
     * Retrieve the name of the command.
     *
     * @return std::string
     */
    virtual std::string getName() = 0;

    /**
     * Retrieve the description of the command.
     *
     * @return std::string
     */
    virtual std::string getDescription() = 0;

};


#endif // COMMAND_H