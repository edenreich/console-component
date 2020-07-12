#include <gtest/gtest.h>

int main(int argc, char const* argv[])
{
    testing::InitGoogleTest();

    int exitCode = RUN_ALL_TESTS();

    return 0;
}
