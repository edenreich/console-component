#include "hello_world.h"

/**
 * Retrieve the name of the command.
 *
 * @return std::string
 */
std::string HelloWorld::getName() { return "hello:world"; }

/**
 * Retrieve the description of the command.
 *
 * @return std::string
 */
std::string HelloWorld::getDescription() { return "output hello world to the console"; }

/**
 * Retrieve the command options.
 *
 * @return Console::Types::AvailableOptions
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
 * @param Console::Interfaces::InputInterface * input
 * @param Console::Interfaces::OutputInterface * output
 * @return ExitCode
 */
ExitCode HelloWorld::handle(Interfaces::InputInterface* input, Interfaces::OutputInterface* output)
{
    for (auto& option : input->getOptions())
    {
        if (input->wantsHelp())
        {
            output->printCommandHelp(this);
            return ExitCode::NeedHelp;
        }
    }

    std::string to = input->ask("To who ?");

    if (to.empty())
    {
        output->writeLine("Hello World..");
    }
    else
    {
        output->writeLine("Hello %s", to.c_str());
    }

    for (auto& option : input->getOptions())
    {
        output->writeLine("alias: %s", option.first.c_str());
        output->writeLine("key: %s", option.second.first.c_str());
        output->writeLine("value: %s", option.second.second.c_str());
    }

    return ExitCode::Ok;
}
