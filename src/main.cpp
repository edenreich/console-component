#include "include/console/application.h"

int main(int argc, char ** argv)
{
    Application app(argc, argv);

    app.setApplicationName("Todo List Application");
    app.setApplicationVersion("1.0");

    // app.setApplicationDescription("Todo List Application");

    // app.setCommandsPath("commands");

    // app.printHelp();

    return app.run();
}
