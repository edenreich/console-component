#include "console/input.h"

#include <iostream>

using namespace Console;


/**
 * Initialize the options
 * 
 * @param Types::Options options
 */
Input::Input(Types::Options options)
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
Types::Options Input::getOptions()
{
    return m_options;
}
