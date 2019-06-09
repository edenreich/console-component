#include "include/console/input.h"

#include <iostream>


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
