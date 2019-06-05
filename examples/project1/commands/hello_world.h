#pragma once

#include <commandline/console/command.h>
#include <commandline/console/types/exit_code.h>

/**
 * @description output hell world to the console
 */
class HelloWorld : public Command
{

public:
    HelloWorld();
    ~HelloWorld();

    ExitCode handle(std::list<std::string> options);

};
