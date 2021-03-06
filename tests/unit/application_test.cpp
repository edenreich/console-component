
#include <gtest/gtest.h>
#include <iostream>
#include <console/application.h>
#include <console/types/exit_code.h>

#include "commands/greetings/hi.h"
#include "commands/greetings/hey.h"

TEST(ApplicationTest, ItReturnsExitCodeNumberTwoIfNoPositionalArgumentWasGivenFirst)
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

TEST(ApplicationTest, ItAddsCommands)
{
    int argc = 1;
    char* argv[] = { (char*)"binary" };

    Console::Application app(argc, argv);

    app.addCommand(new Hey);
    app.addCommand(new Hi);

    unsigned int count = 0;

    for (const auto& commandNamespace : app.getAvailableCommands())
    {
        for (const auto& command : commandNamespace.second)
        {
            count++;
        }
    }

    EXPECT_EQ(2, count);
}

TEST(ApplicationTest, ItGuessTheCommand)
{
    int argc = 2;
    char* argv[] = { (char*)"binary", (char*)"greetings:he" };

    Console::Application app(argc, argv);

    app.addCommand(new Hey); // binary greetings:hey

    testing::internal::CaptureStdout();
    app.run();
    const std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "You probably meant greetings:hey ?\n");
}