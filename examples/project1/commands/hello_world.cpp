#include "hello_world.h"


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
 * Retrieve the command options.
 *
 * @return Types::AvailableOptions
 */
Types::AvailableOptions HelloWorld::getOptions()
{
    Types::AvailableOptions options;

    options["-t"] = std::pair<std::string, std::string>("--to", "say hello to someone instead");

    return options;
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

    output->writeLine("with options: ");
    
    for (auto & option : input->getOptions()) 
    {
        output->writeLine(option);
    }

    if (true /** wrong input for example */) {
        output->printCommandHelp(this);
        return ExitCode::NeedHelp;
    }

    return ExitCode::Ok;
}
