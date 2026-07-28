#include "hello_world.h"

#include <format>

/**
 * Retrieve the name of the command.
 *
 * @return std::string
 */
std::string HelloWorld::getName() noexcept { return "hello:world"; }

/**
 * Retrieve the description of the command.
 *
 * @return std::string
 */
std::string HelloWorld::getDescription() noexcept { return "output hello world to the console"; }

/**
 * Retrieve the command options.
 *
 * @return Console::Types::AvailableOptions
 */
Types::AvailableOptions HelloWorld::getOptions() noexcept
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
ExitCode HelloWorld::handle(Interfaces::InputInterface* input, Interfaces::OutputInterface* output) noexcept
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
        output->writeLine(std::format("Hello {}", to));
    }

    for (auto& option : input->getOptions())
    {
        output->writeLine(std::format("alias: {}", option.first));
        output->writeLine(std::format("key: {}", option.second.first));
        output->writeLine(std::format("value: {}", option.second.second));
    }

    return ExitCode::Ok;
}
