#include "copy_files.h"
#include <iostream>


ExitCode CopyFiles::handle(std::vector<std::string> options)
{
    std::cout << "command copy files was called";

    return ExitCode::Ok;
}
