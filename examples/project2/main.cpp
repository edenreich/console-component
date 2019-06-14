#include <console/application.h>

#include "commands/long_task.h"


int main(int argc, char * argv[])
{
    Console::Application app(argc, argv);

    app.setApplicationName("Todo List Application");
    app.setApplicationUsage("./bin/todo [command] [options]");
    app.setApplicationVersion("1.0");
    app.setAutoPrintHelp(true);

    app.setApplicationDescription("Todo List Application");

    app.addCommand(new LongTask);

    return app.run();
}
