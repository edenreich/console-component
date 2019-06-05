#include <iostream>
#include <typeinfo>
#include <filesystem>
#include "include/console/application.h"
namespace fs = std::filesystem;
//@todo use boost filesystem ?


Application::Application(int & argc, char ** argv)
{
    m_argc = argc;
    m_argv = argv;
}

Application::~Application()
{

}

void Application::setCommandsDirectoryPath(const std::string & dir)
{
    m_dir = dir;
}

void Application::setApplicationName(const std::string & name)
{
    m_name = name;
}

void Application::setApplicationVersion(const std::string & version)
{
    m_version = version;
}

void Application::setApplicationDescription(const std::string & description)
{
    m_description = description;
}

void addCommand(Command & command)
{
    std::string commandName = typeid(command).name();
    m_commands.insert(commandName);
}

void Application::printHelp()
{
    parseDir(m_dir);

    printf("%s \n", m_name.c_str());
    printf("Version: %s \n", m_version.c_str());
    printf("Description: %s \n", m_description.c_str());

    // for (auto const & commands : command) {
    //     printf("%s\t\t%s", command.first, command.second);
    // }
}

int Application::run()
{
    return 1;
}

void Application::parseDir(const std::string & path) const
{
    // 1. list all header files from the given directory path
    for (const auto & entry : fs::directory_iterator(path))
    {
        std::cout << entry.path() << std::endl;
    }

    // 2. parse the @ notations in the file to get @name and @description
    // 3. map command name to description
}
