#include "copy_files.h"

/**
 * Retrieve the name of the command.
 *
 * @return std::string
 */
std::string CopyFiles::getName() { return "copy:files"; }

/**
 * Retrieve the description of the command.
 *
 * @return std::string
 */
std::string CopyFiles::getDescription() { return "copy files from <source> to <dist>"; }

/**
 * Retrieve the command options.
 *
 * @return Console::Types::AvailableOptions
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
 * @param Console::Interfaces::InputInterface * input
 * @param Console::Interfaces::OutputInterface * output
 * @return ExitCode
 */
ExitCode CopyFiles::handle(Interfaces::InputInterface* input, Interfaces::OutputInterface* output)
{
    if (input->wantsHelp())
    {
        output->printCommandHelp(this);
        return ExitCode::NeedHelp;
    }

    if (input->getOption("source").empty() || input->getOption("dest").empty())
    {
        output->warning("wrong options..");
        output->printCommandHelp(this);
        return ExitCode::NeedHelp;
    }

    std::string source = input->getOption("source");
    std::string dest = input->getOption("dest");

    output->info("Copying files from %s to %s", source.c_str(), dest.c_str());

    return ExitCode::Ok;
}
