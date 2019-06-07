
#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include <list>

#include "command.h"

typedef std::list<std::pair<std::string, std::string>> Anotations; // list of anotations, i.e @name, @description
typedef std::list<std::pair<std::string, Anotations>> MetadataTagsCollection; // filename map to anotations

class IApplication {

public:
    virtual void setCommandsDirectoryPath(const std::string & dir) = 0;
    virtual void setApplicationName(const std::string & name) = 0;
    virtual void setApplicationVersion(const std::string & version) = 0;
    virtual void setApplicationDescription(const std::string & description) = 0;
    virtual void addCommand(Command & command) = 0;
    virtual void printHelp() = 0;
    virtual int run() = 0;

};

class Application : public IApplication {

public:
    Application(int & argc, char ** argv);

    virtual ~Application();

    void setCommandsDirectoryPath(const std::string & dir) override;

    void setApplicationName(const std::string & name) override;

    void setApplicationVersion(const std::string & version) override;

    void setApplicationDescription(const std::string & description) override;

    void addCommand(Command & command) override;

    void printHelp() override;

    int run() override;

private:
    void parseDir(const std::string & path) const;

private:
    int m_argc;
    char ** m_argv;
    std::string m_dir;
    std::string m_name;
    std::string m_version;
    std::string m_description;
    Anotations m_anotations;
    MetadataTagsCollection m_metadataTags;
};


#endif // APPLICATION_H