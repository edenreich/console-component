#include <gtest/gtest.h>
#include <console/application.h>
#include <console/input.h>
#include <console/interfaces/input_interface.h>


TEST(InputInterfaceTest, DISABLED_ItOutputAQuestion) {
    int argc = 2;
    char * argv[] = {(char*)"command", (char*)"--option=value"};
    
    Console::Application app(argc, argv);
    
    Console::Interfaces::InputInterface * input = new Console::Input(&app);

    testing::internal::CaptureStdout();
    const std::string answer = input->ask("How old are you ?");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "How old are you ?\n");
    EXPECT_EQ(answer, "31");

    delete input;
}