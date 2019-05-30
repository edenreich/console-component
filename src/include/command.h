#ifndef COMMAND_H
#define COMMAND_H

#include "types/exit_code.h"

class Command {

public:
    Command();
    virtual ~Command();

    virtual ExitCode handle(char * const options[]) = 0;
};

#endif // COMMAND_H