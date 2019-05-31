
#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include "command.h"

class IApplication {

public:
    virtual ~IApplication() = 0;
    virtual int run() = 0;
    virtual void setCommandsPath(const std::string & path) = 0;
    virtual void setApplicationName(const std::string & name) = 0;
    virtual void setApplicationVersion(const std::string & version) = 0;
    virtual void setApplicationDescription(const std::string & descriptions) = 0;
    virtual void addCommand(Command & command) = 0;
    virtual void printHelp() = 0;

};

class Application : public IApplication {

public:
    ~Application() override {}

    int run() override {
        return 1;
    }

    void setCommandsPath(const std::string & path) override;

    void setApplicationName(const std::string & name) override;

    void setApplicationVersion(const std::string & version) override;

    void setApplicationDescription(const std::string & description) override;

    void addCommand(Command & command) override;

    void printHelp() override;

private:
    std::string & path;
    std::string & name;
    std::string & version;
    std::string & description;

};


#endif // APPLICATION_H