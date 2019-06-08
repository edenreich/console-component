
#ifndef APPLICATION_H
#define APPLICATION_H

#include <vector>
#include "types/metadata.h"
#include "application_interface.h"


class Application : public IApplication {

public:
    Application(int & argc, char ** argv);

    virtual ~Application();

    void setCommandsDirectoryPath(const std::string & dir) override;

    void setApplicationName(const std::string & name) override;

    void setApplicationUsage(const std::string & usage) override;

    void setApplicationVersion(const std::string & version) override;

    void setApplicationDescription(const std::string & description) override;

    void addCommand(Command & command) override;

    void printHelp() override;

    int run() override;

private:
    std::vector<std::string> getHeaderFilesFromDir(const std::string & path) const;
    Anotations parseFileMetadata(const std::string & file) const;
    MetadataTagsCollection parseFilesMetadata(std::vector<std::string> files) const;

private:
    int m_argc;
    char ** m_argv;
    std::string m_dir;
    std::string m_name;
    std::string m_usage;
    std::string m_version;
    std::string m_description;
    std::vector<std::string> m_headerFiles;
    Anotations m_anotations;
    MetadataTagsCollection m_metadataTags;
};


#endif // APPLICATION_H