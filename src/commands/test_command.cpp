#include <iostream>
#include "test_command.h"


ExitCode TestCommand::handle(const std::string * options)
{
    std::cout << "command copy files was called";

    return ExitCode::Ok;
}