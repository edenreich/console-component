#include "hello_world.h"
#include <iostream>


ExitCode HelloWorld::handle(std::vector<std::string> options)
{
    std::cout << "command hello world was called";

    return ExitCode::Ok;
}
