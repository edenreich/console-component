#ifndef COLLECTIONS_H
#define COLLECTIONS_H

#include "../interfaces/command_interface.h"
#include <map>
#include <string>

typedef std::map<std::string, CommandInterface *> Commands;


#endif // COLLECTIONS_H