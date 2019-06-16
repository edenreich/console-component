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
    if (input->wantsHelp()) {
        output->printCommandHelp(this);
        return ExitCode::NeedHelp;
    }

    if (input->getOption("source").empty() || input->getOption("dest").empty()) {
        output->printCommandHelp(this);
        return ExitCode::NeedHelp;
    }

    std::string source = input->getOption("source");
    std::string dest = input->getOption("dest");

    output->write("Copying files from "); output->write(source); output->write(" to "); output->writeLine(dest);

    // for (auto & option : input->getOptions()) 
    // {
    //     output->write("alias: "); output->writeLine(option.first);
    //     output->write("key: ");   output->writeLine(option.second.first);
    //     output->write("value: "); output->writeLine(option.second.second);
    // }

    return ExitCode::Ok;
}
