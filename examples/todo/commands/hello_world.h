#pragma once

#include <console/interfaces/command_interface.h>
#include <console/types/collections.h>

namespace Interfaces = Console::Interfaces;
namespace Types = Console::Types;

/**
 * @name hello:world
 */
class HelloWorld : public Interfaces::CommandInterface
{

public:

    /**
     * Retrieve the name of the command.
     *
     * @return std::string
     */
    std::string getName() override;

    /**
     * Retrieve the description of the command.
     *
     * @return std::string
     */
    std::string getDescription() override;

    /**
     * Retrieve the command options.
     *
     * @return Console::Types::AvailableOptions
     */
    Types::AvailableOptions getOptions() override;

    /**
     * Handle the command.
     *
     * @param Console::Interfaces::InputInterface * input
     * @param Console::Interfaces::OutputInterface * output
     * @return ExitCode
     */
    ExitCode handle(Interfaces::InputInterface * input, Interfaces::OutputInterface * output) override;

};
