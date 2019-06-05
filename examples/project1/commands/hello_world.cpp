#include "hello_world.h"


HelloWorld::HelloWorld()
{
    
}

ExitCode HelloWorld::handle(std::list<std::string> options)
{
    std::cout << "command hello world was called";

    return ExitCode::Ok;
}

~HelloWorld::HelloWorld()
{
    
}