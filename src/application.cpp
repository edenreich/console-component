#include <iostream>
#include <typeinfo>
#include "include/console/application.h"


void Application::setCommandsPath(const std::string & path)
{
    this->path = path;
}

void Application::setApplicationName(const std::string & name)
{
    this->name = name;
}

void Application::setApplicationVersion(const std::string & version)
{
    this->version = version;
}

void Application::setApplicationDescription(const std::string & descriptions)
{
    this->description = description;
}

void addCommand(Command & command)
{
    std::cout << typeid(command).name();
}

void Application::printHelp()
{
    printf("%s \n", name.c_str());
    printf("Version: %s \n", version.c_str());
    printf("Description: %s \n", description.c_str());
}