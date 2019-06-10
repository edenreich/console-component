#pragma once

#include <console/interfaces/command_interface.h>

namespace Interfaces = Console::Interfaces;


/**
 * @name long-task
 * @description this is a long running task
 */
class LongTask : public Interfaces::CommandInterface
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
     * Handle the command.
     *
     * @param InputInterface * input
     * @param OutputInterface * output
     * @return ExitCode
     */
    ExitCode handle(Interfaces::InputInterface * input, Interfaces::OutputInterface * output) override;

private:

    /**
     * An example for a long running task
     * 
     * @param Interfaces::OutputInterface * output
     * @return void
     */
    void exampleTask(Interfaces::OutputInterface * output);

    /**
     * An example for a long running task2
     * 
     * @param Interfaces::OutputInterface * output
     * @return void
     */
    void exampleTask2(Interfaces::OutputInterface * output);

};
