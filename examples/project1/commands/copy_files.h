#pragma once

#include <commandline/console/command.h>
#include <commandline/console/types/exit_code.h>

/**
 * @description copy files from <source> to <dist>
 */
class CopyFiles : public Command
{

public:
    CopyFiles();
    ~CopyFiles();

    ExitCode handle(const char * options[]);

};
