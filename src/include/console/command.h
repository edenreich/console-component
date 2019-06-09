#ifndef COMMAND_H
#define COMMAND_H

#include "types/exit_code.h"
#include <string>
#include <vector>


class Command {

public:

    /**
     * Handle the command.
     *
     * @param std::vector<std::string> options
     * @return ExitCode
     */
    virtual ExitCode handle(std::vector<std::string> options) = 0;
};


#endif // COMMAND_H