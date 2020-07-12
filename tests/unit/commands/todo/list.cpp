#include "list.h"

/**
 * Retrieve the name of the command.
 *
 * @return std::string
 */
std::string List::getName() { return "todo:list"; }

/**
 * Retrieve the description of the command.
 *
 * @return std::string
 */
std::string List::getDescription() { return "List all todos"; }

/**
 * Retrieve the command options.
 *
 * @return Console::Types::AvailableOptions
 */
Types::AvailableOptions List::getOptions()
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
ExitCode List::handle(Interfaces::InputInterface* input, Interfaces::OutputInterface* output) { return ExitCode::Ok; }
