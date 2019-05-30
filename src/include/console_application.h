
#ifndef CONSOLE_APPLICATION_H
#define CONSOLE_APPLICATION_H


class IConsoleApplication {

public:
    virtual ~IConsoleApplication() = 0;
    virtual int run() = 0;
    virtual void setCommandsPath(const char * path) = 0;
    virtual void setApplicationName(const char * name) = 0;
    virtual void setApplicationVersion(double version) = 0;
    virtual void setApplicationVersion(const char * version) = 0;
    virtual void setApplicationDescription(const char * description) = 0;
    virtual void printHelp() = 0;

};

class ConsoleApplication : public IConsoleApplication {

public:
    ConsoleApplication(int argc, char * argv[]) {}

    ~ConsoleApplication() override {}

    int run() override {
        return 1;
    }

    void setCommandsPath(const char * path) override;

    void setApplicationName(const char * name) override;

    void setApplicationVersion(double version) override;

    void setApplicationVersion(const char * version) override;

    void setApplicationDescription(const char * description) override;

    void printHelp() override;

private:
    const char * path;
    const char * name;
    double version;
    const char * description;

};

#endif // CONSOLE_APPLICATION_H