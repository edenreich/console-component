#ifndef COMMAND_H
#define COMMAND_H

#include "types/exit_code.h"
#include <string>


class Command {

public:
    virtual ExitCode handle(const std::string * options) = 0;
};


#endif // COMMAND_H