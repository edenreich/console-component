#include "hello_world.h"
#include <iostream>


/**
 * Retrieve the name of the command.
 *
 * @return std::string
 */
std::string HelloWorld::getName()
{
    return "copy-files";
}

/**
 * Retrieve the description of the command.
 *
 * @return std::string
 */
std::string HelloWorld::getDescription()
{
    return "copy files from <source> to <dist>";
}

/**
 * Handle the command.
 *
 * @param std::vector<std::string> options
 * @return ExitCode
 */
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
