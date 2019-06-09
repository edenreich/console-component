#pragma once

#include <console/command.h>
#include <console/types/exit_code.h>
#include <vector>


/**
 * @name hello-world
 * @description output hello world to the console
 */
class HelloWorld : public Command
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
