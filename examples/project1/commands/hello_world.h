#pragma once

#include <console/command.h>
#include <console/types/exit_code.h>


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
     * @param const std::string * options
     * @return ExitCode
     */
    ExitCode handle(const std::string * options);

};
