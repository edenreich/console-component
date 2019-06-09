#include "hello_world.h"

#include <iostream>


/**
 * Retrieve the name of the command.
 *
 * @return std::string
 */
std::string HelloWorld::getName()
{
    return "hello-world";
}

/**
 * Retrieve the description of the command.
 *
 * @return std::string
 */
std::string HelloWorld::getDescription()
{
    return "output hello world to the console";
}

/**
 * Handle the command.
 *
 * @param InputInterface * input
 * @param OutputInterface * output
 * @return ExitCode
 */
ExitCode HelloWorld::handle(Interfaces::InputInterface * input, Interfaces::OutputInterface * output)
{
    output->writeLine("command hello world was called");

    // std::cout << "with options: " << std::endl;
    
    // for (auto & option : options) 
    // {
    //     std::cout << option << std::endl;
    // }

    // return ExitCode::Ok;
}
