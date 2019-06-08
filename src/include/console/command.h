#ifndef COMMAND_H
#define COMMAND_H

#include "types/exit_code.h"
#include <string>


class Command {

public:

    /**
     * Handle the command.
     *
     * @param const std::string * options
     * @return ExitCode
     */
    virtual ExitCode handle(const std::string * options) = 0;
};


#endif // COMMAND_H