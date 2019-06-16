#pragma once

#include <console/interfaces/command_interface.h>
#include <console/types/collections.h>

namespace Interfaces = Console::Interfaces;
namespace Types = Console::Types;

/**
 * @name copy-files
 * @description copy files from <source> to <dist>
 */
class CopyFiles : public Interfaces::CommandInterface
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
     * @return Types::AvailableOptions
     */
    Types::AvailableOptions getOptions() override;

    /**
     * Handle the command.
     *
     * @param InputInterface * input
     * @param OutputInterface * output
     * @return ExitCode
     */
    ExitCode handle(Interfaces::InputInterface * input, Interfaces::OutputInterface * output) override;

};
