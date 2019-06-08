#include <iostream>
#include <typeinfo>
#include <dirent.h>
#include <regex>
#include <fstream>
#include "include/console/types/colors.h"
#include "include/console/application.h"


Application::Application(int & argc, char ** argv)
{
    m_argc = argc;
    m_argv = argv;

    m_dir = "../commands";
    m_usage = "app [command] [options]";
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

void Application::setApplicationUsage(const std::string & usage)
{
    m_usage = usage;
}

void Application::setApplicationVersion(const std::string & version)
{
    m_version = version;
}

void Application::setApplicationDescription(const std::string & description)
{
    m_description = description;
}

void Application::addCommand(Command & command)
{
    // std::string commandName = typeid(command).name();
    // m_commands.insert(commandName);
}

void Application::printHelp()
{

    m_headerFiles = getHeaderFilesFromDir(m_dir);

    m_metadataTags = parseFilesMetadata(m_headerFiles);

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
    for (auto & metadataTag : m_metadataTags)
    {
        std::cout << "  ";
        printf("%s%s%s\t%s", COLOR_GREEN, metadataTag.second.at("@name").c_str(), COLOR_RESET, metadataTag.second.at("@description").c_str());
        std::cout << '\n';
    }
}

int Application::run()
{
    // 1. check what command has been called 
    // 2. create an instance of that class
    // 3. call the handle method and pass it the options

    return ExitCode::Ok;
}

std::vector<std::string> Application::getHeaderFilesFromDir(const std::string & path) const
{
    std::vector<std::string> files;
    DIR * dir;
    struct dirent * entry;

    dir = opendir(path.c_str());

    if (dir == NULL) {
        throw "Could not open directory";
    }

    while ( (entry = readdir(dir)) != NULL )
    {
        std::string file = std::string(entry->d_name);

        if (file == "." || file == "..") {
            continue;
        }

        if (file.substr(file.find_last_of(".") + 1) == "h") {
            files.push_back(file);
        }
    }

    closedir(dir);

    return files;
}

Anotations Application::parseFileMetadata(const std::string & file) const
{
    Anotations anotations;

    std::ifstream handle;
    std::smatch matches;
    std::regex nameRegExp("(@name)\\s(.*)");
    std::regex descriptionRegExp("(@description)\\s(.*)");

    handle.open(file);

    bool foundName = false;
    bool foundDescription = false;

    while (!handle.eof()) {

        std::string line;
        std::getline(handle, line, '\n');

        if (std::regex_search(line, matches, nameRegExp)) {
            anotations["@name"] = matches.str(2);
            foundName = true;
        }

        if (std::regex_search(line, matches, descriptionRegExp)) {
            anotations["@description"] = matches.str(2);
            foundDescription = true;
        }

        if (foundName && foundDescription) {
            break;
        }
    }

    handle.close();

    return anotations;
}

MetadataTagsCollection Application::parseFilesMetadata(std::vector<std::string> files) const
{
    MetadataTagsCollection collection;

    for (std::string & file: files)
    {
        file = m_dir+'/'+file;
        // std::cout << file << std::endl;
        collection[file] = parseFileMetadata(file);
    }

    return collection;
}
