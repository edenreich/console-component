#include "include/console/application.h"
#include "commands/test_command.h"

int main(int argc, char ** argv)
{
    Application app(argc, argv);

    app.setApplicationName("Todo List Application");
    app.setApplicationUsage("todo [command] [options]");
    app.setApplicationVersion("1.0");

    app.setApplicationDescription("Todo List Application");

    app.setCommandsDirectoryPath("src/commands");

    // app.addCommand(new TestCommand);

    app.printHelp();

    return app.run();
}
