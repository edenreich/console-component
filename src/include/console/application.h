
#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include <map>

#include "command.h"

class IApplication {

public:
    virtual void setCommandsPath(const std::string & path) = 0;
    virtual void setApplicationName(const std::string & name) = 0;
    virtual void setApplicationVersion(const std::string & version) = 0;
    virtual void setApplicationDescription(const std::string & description) = 0;
    virtual void addCommand(Command & command) = 0;
    virtual void printHelp() = 0;
    virtual int run() = 0;

};

class Application : public IApplication {

public:
    Application(int &argc, char ** argv);

    virtual ~Application();

    void setCommandsPath(const std::string & path) override;

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
    std::string m_path;
    std::string m_name;
    std::string m_version;
    std::string m_description;
    std::list<std::string> m_commands;
};


#endif // APPLICATION_H