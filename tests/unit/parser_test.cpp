
#include <gtest/gtest.h>
#include <iostream>
#include <console/application.h>
#include <console/types/exit_code.h>

TEST(ParserTest, ItReturnsExitCodeNumberTwoIfNoPositionalArgumentWasGivenFirst)
{
    int argc = 2;
    char* argv[] = { (char*)"--option1=value1", (char*)"--option2=value2" };

    Console::Application app(argc, argv);

    app.setApplicationName("Awesome Application");
    app.setApplicationUsage("todo [command] [options]");
    app.setApplicationVersion("1.0");
    app.setAutoPrintHelp(false);
    app.setApplicationDescription("Todo List Application");

    ExitCode exitCode = app.run();

    EXPECT_EQ(ExitCode::NeedHelp, exitCode);
}