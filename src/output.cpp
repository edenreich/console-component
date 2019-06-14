#include "console/output.h"
#include "console/progress_bar.h"

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

/**
 * Create a progress bar instance.
 * 
 * @param const unsigned int items
 * @return ProgressBar *
 */
ProgressBar * Output::createProgressBar(const unsigned int items)
{
    return new ProgressBar(this, items);
}
