#ifndef COLLECTIONS_H
#define COLLECTIONS_H

#include <map>
#include <string>
#include <vector>

namespace Console
{

    namespace Interfaces
    {
        class CommandInterface;
    }

    namespace Types
    {
        typedef std::pair<std::string, std::string> Option;
        typedef std::map<std::string, Option> Options;
        typedef std::map<std::string, std::map<std::string, Interfaces::CommandInterface*>> Commands;
        typedef std::map<std::string, std::pair<std::string, std::string>> AvailableOptions;
    }
}

#endif // COLLECTIONS_H
