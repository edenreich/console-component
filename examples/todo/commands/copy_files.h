#pragma once

#include <console/interfaces/command_interface.h>
#include <console/types/collections.h>

namespace Interfaces = Console::Interfaces;
namespace Types = Console::Types;

/**
 * @name copy:files
 */
class CopyFiles : public Interfaces::CommandInterface
{

public:
    /**
     * Retrieve the name of the command.
     *
     * @return std::string
     */
    std::string getName() noexcept override;

    /**
     * Retrieve the description of the command.
     *
     * @return std::string
     */
    std::string getDescription() noexcept override;

    /**
     * Retrieve the command options.
     *
     * @return Console::Types::AvailableOptions
     */
    Types::AvailableOptions getOptions() noexcept override;

    /**
     * Handle the command.
     *
     * @param Console::Interfaces::InputInterface * input
     * @param Console::Interfaces::OutputInterface * output
     * @return ExitCode
     */
    [[nodiscard]] ExitCode handle(Interfaces::InputInterface* input, Interfaces::OutputInterface* output) noexcept override;
};
