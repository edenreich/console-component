#include "hello_world.h"
#include <iostream>

ExitCode HelloWorld::handle(const std::string * options)
{
    std::cout << "command hello world was called";

    return ExitCode::Ok;
}
