#include <gtest/gtest.h>
#include <iostream>
#include <console/application.h>
#include <console/output.h>
#include <console/types/colors.h>

#include "commands/greetings/hi.h"
#include "commands/greetings/hey.h"
#include "commands/todo/list.h"

TEST(OutputInterfaceTest, ItOutputsFormattedMessages)
{
    int argc = 1;
    char* argv[1] = { (char*)"scriptname" };

    Console::Application app(argc, argv);

    Console::Output outputInterface(&app);

    testing::internal::CaptureStdout();
    outputInterface.write("%s world", "hello");
    std::string output1 = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    outputInterface.write("%.2f$ item", 0.15);
    std::string output2 = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output1, "hello world");
    EXPECT_EQ(output2, "0.15$ item");
}

TEST(OutputInterfaceTest, ItOutputsColoredMessages)
{
    int argc = 1;
    char* argv[1] = { (char*)"scriptname" };

    Console::Application app(argc, argv);

    Console::Output outputInterface(&app);

    testing::internal::CaptureStdout();
    outputInterface.write(Console::Types::Colors::RED, "Error occured on line %d at in this file", 105);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "\x1B[41mError occured on line 105 at in this file\x1B[0m");
}

TEST(OutputInterfaceTest, ItOutputsAnError)
{
    int argc = 1;
    char* argv[1] = { (char*)"scriptname" };

    Console::Application app(argc, argv);

    Console::Output outputInterface(&app);

    testing::internal::CaptureStdout();
    outputInterface.error("Error occured on line %d at in this file", 105);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "\x1B[41mError occured on line 105 at in this file\x1B[0m\n");
}

TEST(OutputInterfaceTest, ItOutputsApplicationHelp)
{
    int argc = 1;
    char* argv[1] = { (char*)"scriptname" };

    Console::Application app(argc, argv);

    Console::Output outputInterface(&app);

    testing::internal::CaptureStdout();
    outputInterface.printHelp();
    const std::string output = testing::internal::GetCapturedStdout();

    const std::string expectedOutput = "\x1B[32m\x1B[0m\n\x1B[33mVersion: \x1B[0m\n\n\x1B[33m"
                                       "Usage:\x1B[0m\n  app [command] [options]\n\n\n\x1B[33mOptions:\x1B[0m\n"
                                       "  -h, --help\tDisplay this help message\n\n\x1B[33m"
                                       "Available Commands:\x1B[0m\n\n";

    EXPECT_EQ(output, expectedOutput);
}

TEST(OutputInterfaceTest, ItOutputsApplicationAvailableCommands)
{
    int argc = 1;
    char* argv[1] = { (char*)"scriptname" };

    Console::Application app(argc, argv);

    Console::Output outputInterface(&app);

    app.addCommand(new List);

    testing::internal::CaptureStdout();
    outputInterface.printHelp();
    const std::string output = testing::internal::GetCapturedStdout();

    const std::string expectedOutput = "\x1B[32m\x1B[0m\n\x1B[33mVersion: \x1B[0m\n\n\x1B[33m"
                                       "Usage:\x1B[0m\n  app [command] [options]\n\n\n\x1B[33mOptions:\x1B[0m\n"
                                       "  -h, --help\tDisplay this help message\n\n\x1B[33m"
                                       "Available Commands:\x1B[0m\n"
                                       "\x1B[33m todo\n\x1B[0m"
                                       "\x1B[32m  todo:list\x1B[0m\tList all todos\n\n";

    EXPECT_EQ(output, expectedOutput);
}

TEST(OutputInterfaceTest, ItOutputsApplicationAvailableCommandsInDifferentNamespaces)
{
    int argc = 1;
    char* argv[1] = { (char*)"scriptname" };

    Console::Application app(argc, argv);

    Console::Output outputInterface(&app);

    app.addCommand(new Hi); // namespace of greetings
    app.addCommand(new Hey); // namespace of greetings
    app.addCommand(new List); // namespace of todo

    testing::internal::CaptureStdout();
    outputInterface.printHelp();
    const std::string output = testing::internal::GetCapturedStdout();

    const std::string expectedOutput = "\x1B[32m\x1B[0m\n\x1B[33mVersion: \x1B[0m\n\n\x1B[33m"
                                       "Usage:\x1B[0m\n  app [command] [options]\n\n\n\x1B[33mOptions:\x1B[0m\n"
                                       "  -h, --help\tDisplay this help message\n\n\x1B[33m"
                                       "Available Commands:\x1B[0m\n"
                                       "\x1B[33m greetings\n\x1B[0m"
                                       "\x1B[32m  greetings:hi\x1B[0m\tSay Hi\n"
                                       "\x1B[32m  greetings:hey\x1B[0m\tSay Hey\n"
                                       "\x1B[33m todo\n\x1B[0m"
                                       "\x1B[32m  todo:list\x1B[0m\tList all todos\n\n";

    EXPECT_EQ(output, expectedOutput);
}
