#include <iostream>
#include <typeinfo>
#include <regex>

#include "console/application.h"
#include "console/input.h"
#include "console/output.h"

using namespace Console;


/**
 * - Initialize the arguments count
 * - initialize the arguments values
 * 
 * @param int & argc
 * @param char ** argv
 */
Application::Application(int & argc, char ** argv)
{
    m_argc = argc;
    m_argv = argv;

    m_output = nullptr;
    m_input = nullptr;

    m_usage = "app [command] [options]";
    m_printHelpAutomatically = false;
}

/**
 * Destroy the application.
 */
Application::~Application()
{
    for (auto & command : getAvailableCommands())
    {
        delete command.second;
    }

    delete m_output;
    delete m_input;
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
 * Getter for the application name.
 *
 * @return std::string
 */
std::string Application::getApplicationName()
{
    return m_name;
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
 * Getter for the application usage.
 *
 * @return std::string
 */
std::string Application::getApplicationUsage()
{
    return m_usage;
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
 * Getter for the application version.
 *
 * @return std::string
 */
std::string Application::getApplicationVersion()
{
    return m_version;
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
 * Getter for the application description.
 *
 * @return std::string
 */
std::string Application::getApplicationDescription()
{
    return m_description;
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
 * Getter for the available commands,
 * registered by the application.
 *
 * @return Types::Commands
 */
Types::Commands Application::getAvailableCommands()
{
    return m_commands;
}

/**
 * Add a command instance to the application.
 *
 * @param const std::string & option
 * @param const std::string & description
 * @param const std::string & alias
 * @return void
 */
void Application::addGlobalOption(const std::string & option, const std::string & description, const std::string & alias)
{   
    m_options[alias] = std::pair<std::string, std::string>(option, description);
}

/**
 * Getter for the available global options.
 *
 * @return Types::AvailableOptions
 */
Types::AvailableOptions Application::getAvailableGlobalOptions()
{
    return m_options;
}

/**
 * Set print help to automatically.
 *
 * @param bool yes
 * @return void
 */
void Application::setAutoPrintHelp(bool yes)
{
    m_printHelpAutomatically = yes;
}

/**
 * Indicates if the application should print
 * the help automatically.
 *
 * @return bool
 */
bool Application::shouldPrintHelpAutomatically()
{
    return m_printHelpAutomatically;
}

/**
 * Getter for the input interface.
 * 
 * @return Interfaces::InputInterface
 */
Interfaces::InputInterface * Application::getInput()
{
    return m_input;
}

/**
 * Run the console application.
 * 
 * @return ExitCode
 */
ExitCode Application::run()
{
    m_input = new Input(this);
    m_output = new Output(this);
    std::vector<std::string> arguments(m_argv + 1, m_argv + m_argc);
    Types::Options options;
    std::string requestedCommand;
    std::smatch matchedOption;

    for (std::size_t i = 0; i != arguments.size(); ++i) {
        std::regex isOption("^--?(.*)");

        if (std::regex_search(arguments[i], matchedOption, isOption)) {
            options.push_back(matchedOption.str());
            continue;
        }

        requestedCommand = arguments[i];
    }

    for (auto & command : getAvailableCommands())
    {
        if (requestedCommand.empty() && shouldPrintHelpAutomatically()) {
            m_output->printHelp();
            break;
        }

        if (command.second->getName() == requestedCommand) {
            m_input->setOptions(options);
            return command.second->handle(m_input, m_output);
        }
    }

    return ExitCode::NeedHelp;
}
