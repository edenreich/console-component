#pragma once

#include <console/command.h>
#include <console/types/exit_code.h>

/**
 * @name hello-world
 * @description output hell world to the console
 */
class HelloWorld : public Command
{

public:
    ExitCode handle(const std::string * options);

};
