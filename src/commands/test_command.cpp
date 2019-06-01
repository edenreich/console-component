#include "test_command.h"


ExitCode TestCommand::handle(std::vector<std::string> options)
{
    std::cout << "command copy files was called";
    std::cout << "Options: " << options;

    return ExitCode::Ok;
}