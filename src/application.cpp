#include <iostream>
#include <typeinfo>
#include <regex>

#include "console/types/colors.h"
#include "console/application.h"
#include "console/input.h"
#include "console/output.h"


using namespace Console;


/**
 * - Initialize the arguments count
 * - initialize the arguments values
 */
Application::Application(int & argc, char ** argv)
{
    m_argc = argc;
    m_argv = argv;

    m_usage = "app [command] [options]";
}

/**
 * Destroy the application.
 */
Application::~Application()
{
    for (auto & command : m_commands)
    {
        // just for safety delete all memory allocations
        delete command.second;
    }

    m_commands.clear();
}

/**
 * Setter for the application name.
 *
 * @param const std::string & name
 * @return void
 */
void Application::setApplicationName(const std::string & name)
{
    m_name = name;
}

/**
 * Setter for the application usage.
 *
 * @param const std::string & usage
 * @return void
 */
void Application::setApplicationUsage(const std::string & usage)
{
    m_usage = usage;
}

/**
 * Setter for the application version.
 *
 * @param const std::string & version
 * @return void
 */
void Application::setApplicationVersion(const std::string & version)
{
    m_version = version;
}

/**
 * Setter for the application description.
 *
 * @param const std::string & description
 * @return void
 */
void Application::setApplicationDescription(const std::string & description)
{
    m_description = description;
}

/**
 * Add a command instance to the application.
 *
 * @param CommandInterface * command
 * @return void
 */
void Application::addCommand(Interfaces::CommandInterface * command)
{
    std::string commandName = typeid(*(command)).name();
    
    m_commands[commandName] = command;
}

/**
 * Print the help message.
 *
 * @return void
 */
void Application::printHelp()
{
    // @todo refactor this into it's own template file maybe

    printf("%s%s%s", COLOR_GREEN, m_name.c_str(), COLOR_RESET);
    std::cout << '\n';
    printf("Version: %s%s%s", COLOR_YELLOW, m_version.c_str(), COLOR_RESET);
    std::cout << '\n';
    printf("Description: %s", m_description.c_str());
    std::cout << '\n';
    std::cout << '\n';

    // Usage
    printf("%sUsage:%s", COLOR_YELLOW, COLOR_RESET);
    std::cout << '\n';
    printf("  %s", m_usage.c_str());
    std::cout << '\n';
    std::cout << '\n';
    
    // Options
    printf("%sOptions:%s", COLOR_YELLOW, COLOR_RESET);
    std::cout << '\n';
    printf("  %s\t%s", "-h, --help", "Display this help message");
    std::cout << '\n';
    std::cout << '\n';

    // Available Commands
    printf("%sAvailable Commands:%s\n", COLOR_YELLOW, COLOR_RESET);
    for (auto & command : m_commands)
    {
        std::cout << "  ";
        printf("%s%s%s\t%s", COLOR_GREEN, command.second->getName().c_str(), COLOR_RESET, command.second->getDescription().c_str());
        std::cout << '\n';
    }
}

/**
 * Run the console application.
 * 
 * @return ExitCode
 */
ExitCode Application::run()
{
    std::vector<std::string> arguments(m_argv + 1, m_argv + m_argc);
    Types::Options options;
    std::string requestedCommand;
    std::smatch matchedOption;

    for (std::size_t i = 0; i != arguments.size(); ++i) {
        std::regex isOption("^--(.*)");

        if (std::regex_search(arguments[i], matchedOption, isOption)) {
            options.push_back(matchedOption.str());
            continue;
        }

        requestedCommand = arguments[i];
    }

    for (auto & command : m_commands)
    {
        if (requestedCommand.empty()) {
            printHelp();
            break;
        }

        if (command.second->getName() == requestedCommand) {
            Input input(options);
            Output output;
            command.second->handle(&input, &output);
            break;
        }
    }

    return ExitCode::Ok;
}
