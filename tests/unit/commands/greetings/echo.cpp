#include "echo.h"

/**
 * Retrieve the name of the command.
 *
 * @return std::string
 */
std::string Echo::getName() noexcept { return "greetings:echo"; }

/**
 * Retrieve the description of the command.
 *
 * @return std::string
 */
std::string Echo::getDescription() noexcept { return "Echo the positional argument"; }

/**
 * Retrieve the command options.
 *
 * @return Console::Types::AvailableOptions
 */
Types::AvailableOptions Echo::getOptions() noexcept
{
    Types::AvailableOptions options;

    return options;
}

/**
 * Handle the command.
 *
 * @param Console::Interfaces::InputInterface * input
 * @param Console::Interfaces::OutputInterface * output
 * @return ExitCode
 */
ExitCode Echo::handle(Interfaces::InputInterface* input, Interfaces::OutputInterface* output) noexcept
{
    std::string argument = input->getArgument();

    if (!argument.empty())
    {
        output->writeLine(argument);
    }

    return ExitCode::Ok;
}
