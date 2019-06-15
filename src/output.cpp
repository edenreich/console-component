#include "console/output.h"
#include "console/progress_bar.h"

#include <iostream>
#include "console/types/colors.h"

using namespace Console;


/**
 * Initialize the application interface.
 * 
 * @param Interfaces::ApplicationInterface * app
 */
Output::Output(Interfaces::ApplicationInterface * app)
{
    m_app = app;
}

/**
 * Print the help message.
 *
 * @return void
 */
void Output::printHelp()
{
    printf("%s%s%s\n", COLOR_GREEN, m_app->getApplicationName().c_str(), COLOR_RESET);
    printf("Version: %s%s%s\n", COLOR_YELLOW, m_app->getApplicationVersion().c_str(), COLOR_RESET);
    printf("Description: %s\n\n", m_app->getApplicationDescription().c_str());

    // Usage
    printf("%sUsage:%s\n", COLOR_YELLOW, COLOR_RESET);
    printf("  %s\n\n", m_app->getApplicationUsage().c_str());
    
    // Options
    printf("%sOptions:%s\n", COLOR_YELLOW, COLOR_RESET);
    printf("  %s\t%s\n", "-h, --help", "Display this help message");
    for (auto & option : m_app->getAvailableGlobalOptions())
    {
        printf("  ");
        printf("%s, %s\t%s\n", option.first.c_str(), option.second.first.c_str(), option.second.second.c_str());
    }

    // Available Commands
    printf("\n%sAvailable Commands:%s\n", COLOR_YELLOW, COLOR_RESET);
    for (auto & command : m_app->getAvailableCommands())
    {
        printf("  ");
        printf("%s%s%s\t%s\n", COLOR_GREEN, command.second->getName().c_str(), COLOR_RESET, command.second->getDescription().c_str());
    }
}

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
