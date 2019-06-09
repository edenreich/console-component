#pragma once

#include <console/interfaces/command_interface.h>
#include <console/types/exit_code.h>
#include <vector>


/**
 * @name copy-files
 * @description copy files from <source> to <dist>
 */
class CopyFiles : public CommandInterface
{

public:

    /**
     * Retrieve the name of the command.
     *
     * @return std::string
     */
    std::string getName() override;

    /**
     * Retrieve the description of the command.
     *
     * @return std::string
     */
    std::string getDescription() override;

    /**
     * Handle the command.
     *
     * @param std::vector<std::string> options
     * @return ExitCode
     */
    ExitCode handle(std::vector<std::string> options) override;

};
