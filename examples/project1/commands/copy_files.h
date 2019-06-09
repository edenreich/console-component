#pragma once

#include <console/command.h>
#include <console/types/exit_code.h>
#include <vector>


/**
 * @name copy-files
 * @description copy files from <source> to <dist>
 */
class CopyFiles : public Command
{

public:

    /**
     * Handle the command.
     *
     * @param std::vector<std::string> options
     * @return ExitCode
     */
    ExitCode handle(std::vector<std::string> options);

};
