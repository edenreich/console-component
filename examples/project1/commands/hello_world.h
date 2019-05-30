#pragma once

#include <command.h>
#include <types/exit_code.h>

/**
 * @description output hell world to the console
 */
class HelloWorld : public Command
{

public:
    HelloWorld();
    ~HelloWorld();

    ExitCode handle(const char * options[]);

};
