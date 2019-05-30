#include <stdio.h>
#include <stdlib.h>
#include "include/console_application.h"


void ConsoleApplication::setCommandsPath(const char * path)
{
    this->path = path;
}

void ConsoleApplication::setApplicationName(const char * name)
{
    this->name = name;
}

void ConsoleApplication::setApplicationVersion(double version)
{
    this->version = version;
}

void ConsoleApplication::setApplicationVersion(const char * version)
{
    this->version = atof(version);
}

void ConsoleApplication::setApplicationDescription(const char * description)
{
    this->description = description;
}

void ConsoleApplication::printHelp()
{
    printf("%s \n", name);
    printf("Version: %lf \n", version);
    printf("Description: %s \n", description);
}