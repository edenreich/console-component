#ifndef COLLECTIONS_H
#define COLLECTIONS_H

#include <map>
#include <string>
#include <vector>

namespace Console::Interfaces {

    class CommandInterface;

}

namespace Console {

    namespace  Types {

        typedef std::vector<std::string> Options;
        typedef std::map<std::string, Interfaces::CommandInterface *> Commands;

    }

}


#endif // COLLECTIONS_H
