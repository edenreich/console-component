#pragma once

#include <console/command.h>
#include <console/types/exit_code.h>

/**
 * @description copy files from <source> to <dist>
 */
class CopyFiles : public Command
{

public:
    CopyFiles();
    ~CopyFiles();

    ExitCode handle(const std::string * options);

};
