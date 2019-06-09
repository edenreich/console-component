#include "console/output.h"

#include <iostream>

using namespace Console;


/**
 * Retrieve an input from the user.
 *
 * @param const std::string & line
 * @return void
 */
void Output::writeLine(const std::string & line)
{
    std::cout << line << std::endl;
}
