#ifndef APPLICATION_INTERFACE_H
#define APPLICATION_INTERFACE_H


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


#endif // APPLICATION_INTERFACE_H