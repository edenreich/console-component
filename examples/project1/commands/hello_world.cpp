#include "hello_world.h"
#include <iostream>


ExitCode HelloWorld::handle(std::vector<std::string> options)
{
    std::cout << "command hello world was called" << std::endl;

    std::cout << "with options: " << std::endl;
    
    for (auto & option : options) 
    {
        std::cout << option << std::endl;
    }

    return ExitCode::Ok;
}
