#include <console/application.h>

#include "commands/long_task.h"


int main(int argc, char * argv[])
{
    Console::Application app(argc, argv);

    app.setApplicationName("Http Client");
    app.setApplicationUsage("./bin/http <command> [options]");
    app.setApplicationVersion("1.0");
    app.setAutoPrintHelp(true);

    app.setApplicationDescription("This is my awesome http client.");

    app.addCommand(new LongTask);

    return app.run();
}
