
#include <macro/colors.h>
#include <types/exit_code.h>
#include <console_application.h>

int main(int argc, char * argv[])
{
    ConsoleApplication app(argc, argv);

    app.setApplicationName("Todo List Application");
    app.setApplicationVersion("1.0");

    app.setApplicationDescription("Todo List Application");

    return app.run();
}
