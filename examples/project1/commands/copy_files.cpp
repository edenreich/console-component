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
 * @param std::vector<std::string> options
 * @return ExitCode
 */
ExitCode CopyFiles::handle(std::vector<std::string> options)
{
    std::cout << "command copy files was called\n" << std::endl;

    std::cout << "with options: " << std::endl;
    
    for (auto & option : options) 
    {
        std::cout << option << std::endl;
    }

    return ExitCode::Ok;
}
