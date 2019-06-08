#pragma once

#include <console/command.h>
#include <console/types/exit_code.h>


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
     * @param const std::string * options
     * @return ExitCode
     */
    ExitCode handle(const std::string * options);

};
