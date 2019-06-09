#include "copy_files.h"
#include <iostream>


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
