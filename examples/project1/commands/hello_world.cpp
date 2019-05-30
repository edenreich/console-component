#include "hello_world.h"


HelloWorld::HelloWorld()
{
    
}

ExitCode HelloWorld::handle(const char * options[])
{
    std::cout << "command hello world was called";
    std::cout << "Options: " << options;

    return ExitCode::Ok;
}

~HelloWorld::HelloWorld()
{
    
}