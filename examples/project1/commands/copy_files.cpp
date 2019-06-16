#include "copy_files.h"


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
 * Retrieve the command options.
 *
 * @return Types::AvailableOptions
 */
Types::AvailableOptions CopyFiles::getOptions()
{
    Types::AvailableOptions options;

    options["-s"] = std::pair<std::string, std::string>("--source", "specific the source");
    options["-d"] = std::pair<std::string, std::string>("--dest", "specific the destination");

    return options;
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

    if (true/** wrong input for example */) {
        output->printCommandHelp(this);
        return ExitCode::NeedHelp;
    }

    return ExitCode::Ok;
}
