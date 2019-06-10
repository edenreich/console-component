#ifndef COLLECTIONS_H
#define COLLECTIONS_H

#include <map>
#include <utility>
#include <string>
#include <vector>

namespace Console::Interfaces {

    class CommandInterface;

}

namespace Console {

    namespace  Types {

        typedef std::vector<std::string> Options;
        typedef std::map<std::string, Interfaces::CommandInterface *> Commands;
        typedef std::map<std::string, std::pair<std::string, std::string>> AvailableOptions;

    }

}


#endif // COLLECTIONS_H
