
#ifndef APPLICATION_H
#define APPLICATION_H

#include "types/metadata.h"
#include "application_interface.h"


class Application : public IApplication {

public:

    /**
     * - Initialize the arguments count
     * - initalize the arguments values
     */
    Application(int & argc, char ** argv);

    /**
     * Destroy the application.
     */
    virtual ~Application();

    /**
     * Setter for the commands directory path
     * This is where the anotation parser will look
     * for command @name and command @description.
     *
     * @param const std::string & dir
     * @return void
     */
    void setCommandsDirectoryPath(const std::string & dir) override;

    /**
     * Setter for the application name.
     *
     * @param const std::string & name
     * @return void
     */
    void setApplicationName(const std::string & name) override;

    /**
     * Setter for the application usage.
     *
     * @param const std::string & usage
     * @return void
     */
    void setApplicationUsage(const std::string & usage) override;
    
    /**
     * Setter for the application version.
     *
     * @param const std::string & version
     * @return void
     */
    void setApplicationVersion(const std::string & version) override;
    
    /**
     * Setter for the application description.
     *
     * @param const std::string & description
     * @return void
     */
    void setApplicationDescription(const std::string & description) override;
    
    /**
     * Add a command instance to the application.
     * 
     * @param Command & command
     * @return void
     */
    void addCommand(Command & command) override;

    /**
     * Print the help message.
     *
     * @return void
     */
    void printHelp() override;

    /**
     * Run the console application.
     * 
     * @return ExitCode
     */
    ExitCode run() override;

private:

    /**
     * Store the header files names
     * from the commands directory.
     *
     * @param const std::string & path
     * @return HeaderFiles
     */
    HeaderFiles getHeaderFilesFromDir(const std::string & path) const;
    
    /**
     * Parse the metadata of
     * a given header file.
     *
     * @param const std::string & file
     * @return Anotations
     */
    Anotations parseFileMetadata(const std::string & file) const;
    
    /**
     * Parse the metadata of
     * each header file.
     *
     * @param HeaderFiles files
     * @return AnotationsCollection
     */
    AnotationsCollection parseFilesMetadata(HeaderFiles files) const;

private:

    /**
     * Store the arguments count.
     *
     * @var int
     */
    int m_argc;

    /**
     * Store the arguments values.
     *
     * @var char ** m_argv
     */
    char ** m_argv;

    /**
     * Store the path 
     * of the commands directory.
     *
     * @var std::string
     */
    std::string m_dir;

    /**
     * Store the name 
     * of the application.
     *
     * @var std::string
     */
    std::string m_name;

    /**
     * Store the application
     * usage instructions.
     *
     * @var std::string
     */
    std::string m_usage;

    /**
     * Store the application version.
     *
     * @var std::string
     */
    std::string m_version;

    /**
     * Store the application description.
     *
     * @var std::string
     */
    std::string m_description;

    /**
     * Store the application 
     * commands header file names.
     *
     * @var HeaderFiles
     */
    HeaderFiles m_headerFiles;

    /**
     * Store the anotations
     * (i.e @name, @description)
     * 
     * @var Anotations
     */
    Anotations m_anotations;

    /**
     * Store the header file name
     * mapped to anotations.
     * 
     * @var AnotationsCollection
     */
    AnotationsCollection m_metadataTags;

};


#endif // APPLICATION_H