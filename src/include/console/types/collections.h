#ifndef COLLECTIONS_H
#define COLLECTIONS_H

#include <map>
#include <memory>
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
        using Option = std::pair<std::string, std::string>;
        using Options = std::map<std::string, Option>;
        using Commands = std::map<std::string, std::map<std::string, std::unique_ptr<Interfaces::CommandInterface>>>;
        using AvailableOptions = std::map<std::string, std::pair<std::string, std::string>>;
    }
}

#endif // COLLECTIONS_H
