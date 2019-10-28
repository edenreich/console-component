#include "include/console/input.h"

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
    std::cout << question << '\n';

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

/**
 * Determine if the -h or --help flag
 * was supplied.
 * 
 * @return bool
 */
bool Input::wantsHelp()
{
    for (auto & option : getOptions()) 
    {
        if (option.first == "h" || option.second.first == "help")
            return true;
    }

    return false;
}

/**
 * Retrieve the option value
 * by given option.
 * 
 * @param const std::string & option
 * @return std::string
 */
std::string Input::getOption(const std::string & option)
{
    for (auto & availableOption : getOptions()) 
    {
        if (availableOption.second.first == option)
            return availableOption.second.second;
    }

    return "";
}

/**
 * Retrieve the option value
 * by given option and alias.
 * 
 * @param const std::string & option
 * @param const std::string & alias
 * @return std::string
 */
std::string Input::getOption(const std::string & option, const std::string & alias)
{
    for (auto & availableOption : getOptions()) 
    {
        if (availableOption.first == alias || availableOption.second.first == option)
            return availableOption.second.second;
    }

    return "";
}