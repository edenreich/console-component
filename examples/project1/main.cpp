#include <console/application.h>
#include "commands/copy_files.h"
#include "commands/hello_world.h"


int main(int argc, char * argv[])
{
    Application app(argc, argv);

    app.setApplicationName("Todo List Application");
    app.setApplicationUsage("./bin/todo [command] [options]");
    app.setApplicationVersion("1.0");

    app.setApplicationDescription("Todo List Application");

    app.setCommandsDirectoryPath("commands");
    
    app.printHelp();

    app.addCommand(new CopyFiles);
    app.addCommand(new HelloWorld);

    return app.run();
}
