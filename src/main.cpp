#include "include/console/application.h"

int main(int argc, char ** argv)
{
    Application app(argc, argv);

    app.setApplicationName("Todo List Application");
    app.setApplicationUsage("todo [command] [options]");
    app.setApplicationVersion("1.0");

    app.setApplicationDescription("Todo List Application");

    app.setCommandsDirectoryPath("src/commands");

    app.printHelp();

    return app.run();
}
