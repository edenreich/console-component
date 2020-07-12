#include "hey.h"

/**
 * Retrieve the name of the command.
 *
 * @return std::string
 */
std::string Hey::getName() { return "greetings:hey"; }

/**
 * Retrieve the description of the command.
 *
 * @return std::string
 */
std::string Hey::getDescription() { return "Say Hey"; }

/**
 * Retrieve the command options.
 *
 * @return Console::Types::AvailableOptions
 */
Types::AvailableOptions Hey::getOptions()
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
ExitCode Hey::handle(Interfaces::InputInterface* input, Interfaces::OutputInterface* output) { return ExitCode::Ok; }
