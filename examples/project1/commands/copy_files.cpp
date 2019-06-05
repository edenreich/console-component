#include "copy_files.h"


CopyFiles::CopyFiles()
{

}

ExitCode CopyFiles::handle(std::list<std::string> options)
{
    std::cout << "command copy files was called";

    return ExitCode::Ok;
}

~CopyFiles::CopyFiles()
{
    
}