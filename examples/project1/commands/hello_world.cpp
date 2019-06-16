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
    for (auto & option : input->getOptions()) 
    {
        if (input->wantsHelp()) {
            output->printCommandHelp(this);
            return ExitCode::NeedHelp;
        }
    }

    std::string to = input->getOption("to", "t");

    if (to.empty()) {
        output->writeLine("Hello World..");
    }
    else
    {
        output->write("Hello "); output->writeLine(to);
    }

    // for (auto & option : input->getOptions()) 
    // {
    //     output->write("alias: "); output->writeLine(option.first);
    //     output->write("key: ");   output->writeLine(option.second.first);
    //     output->write("value: "); output->writeLine(option.second.second);
    // }

    return ExitCode::Ok;
}
