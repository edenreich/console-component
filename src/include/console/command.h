#ifndef COMMAND_H
#define COMMAND_H

#include "types/exit_code.h"
#include <vector>
#include <string>

class Command {

public:
    Command();
    virtual ~Command();

    virtual ExitCode handle(std::vector<std::string> options) = 0;
};

#endif // COMMAND_H