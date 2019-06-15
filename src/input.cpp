#include "console/input.h"

#include <iostream>

using namespace Console;


/**
 * Initialize the application interface.
 * 
 * @param Interfaces::ApplicationInterface * app
 */
Input::Input(Interfaces::ApplicationInterface * app)
{
    m_app = app;
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


/**
 * Setter for the parsed options.
 *
 * @return Types::Options options
 * @return void
 */
void Input::setOptions(Types::Options options)
{
    m_options = options;
}
