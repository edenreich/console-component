#include "console/input.h"

#include <iostream>

using namespace Console;



/**
 * - Initialize the options
 */
Input::Input(Options options)
{
    m_options = options;
}

/**
 * Retrieve an input from the user.
 *
 * @param const std::string & question
 * @return std::string
 */
std::string Input::ask(const std::string & question)
{
    std::string input;

    std::cin >> input;

    return input;
}

/**
 * Retrieve the parsed options.
 *
 * @return Options
 */
Options Input::getOptions()
{
    return m_options;
}
