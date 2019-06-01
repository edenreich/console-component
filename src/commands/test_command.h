#pragma once

#include "../include/console/command.h"
#include "../include/console/types/exit_code.h"

/**
 * @name copy-files
 * @description copy files from <source> to <dist>
 */
class TestCommand : public Command
{

public:
    ExitCode handle(std::list<std::string> options);

};
