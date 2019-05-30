#include "copy_files.h"


CopyFiles::CopyFiles()
{

}

ExitCode CopyFiles::handle(const char * options[])
{
    std::cout << "command copy files was called";
    std::cout << "Options: " << options;

    return ExitCode::Ok;
}

~CopyFiles::CopyFiles()
{
    
}