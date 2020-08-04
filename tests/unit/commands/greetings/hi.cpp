#include "hi.h"

/**
 * Retrieve the name of the command.
 *
 * @return std::string
 */
std::string Hi::getName() { return "greetings:hi"; }

/**
 * Retrieve the description of the command.
 *
 * @return std::string
 */
std::string Hi::getDescription() { return "Say Hi"; }

/**
 * Retrieve the command options.
 *
 * @return Console::Types::AvailableOptions
 */
Types::AvailableOptions Hi::getOptions()
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
ExitCode Hi::handle(Interfaces::InputInterface* input, Interfaces::OutputInterface* output) { return ExitCode::Ok; }
