#ifndef METADATA_H
#define METADATA_H

#include <list>
#include <string>


typedef std::list<std::pair<std::string, std::string>> Anotations; // list of anotations, i.e @name, @description
typedef std::list<std::pair<std::string, Anotations>> MetadataTagsCollection; // filename map to anotations


#endif // METADATA_H