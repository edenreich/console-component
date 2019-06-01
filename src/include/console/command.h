#ifndef COMMAND_H
#define COMMAND_H

#include "types/exit_code.h"
#include <vector>
#include <string>
#include <list>

class Command {

public:
    virtual ExitCode handle(std::list<std::string> options) = 0;
};

#endif // COMMAND_H