#include "hi.h"

/**
 * Retrieve the name of the command.
 *
 * @return std::string
 */
std::string Hi::getName() noexcept { return "greetings:hi"; }

/**
 * Retrieve the description of the command.
 *
 * @return std::string
 */
std::string Hi::getDescription() noexcept { return "Say Hi"; }

/**
 * Retrieve the command options.
 *
 * @return Console::Types::AvailableOptions
 */
Types::AvailableOptions Hi::getOptions() noexcept
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
ExitCode Hi::handle(Interfaces::InputInterface* input, Interfaces::OutputInterface* output) noexcept { return ExitCode::Ok; }
