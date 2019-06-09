#include "copy_files.h"

#include <iostream>


/**
 * Retrieve the name of the command.
 *
 * @return std::string
 */
std::string CopyFiles::getName()
{
    return "copy-files";
}

/**
 * Retrieve the description of the command.
 *
 * @return std::string
 */
std::string CopyFiles::getDescription()
{
    return "copy files from <source> to <dist>";
}

/**
 * Handle the command.
 *
 * @param InputInterface * input
 * @param OutputInterface * output
 * @return ExitCode
 */
ExitCode CopyFiles::handle(Interfaces::InputInterface * input, Interfaces::OutputInterface * output)
{
    output->writeLine("Copying files..");

    output->writeLine("with options: ");
    
    for (auto & option : input->getOptions()) 
    {
        output->writeLine(option);
    }

    return ExitCode::Ok;
}
