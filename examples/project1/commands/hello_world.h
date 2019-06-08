#pragma once

#include <console/command.h>
#include <console/types/exit_code.h>

/**
 * @description output hell world to the console
 */
class HelloWorld : public Command
{

public:
    HelloWorld();
    ~HelloWorld();

    ExitCode handle(const std::string * options);

};
