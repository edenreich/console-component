![Build](https://github.com/edenreich/console-component/workflows/Build/badge.svg?branch=master) ![Lint](https://github.com/edenreich/console-component/workflows/Lint/badge.svg?branch=master)

# Console Component

An easy to use component for building powerful console applications written in C++.

- [Console Component](#Console-Component)
  - [Preview](#Preview)
  - [Install](#Install)
  - [Usage](#Usage)
  - [Build](#Build)
  - [Target](#Target)
  - [Motivation](#Motivation)
  - [Contribution](#Contribution)

## Preview

- Install:
<p align="left"><img src="https://drive.google.com/uc?export=view&id=1iRNoWwXo0ZsWZ8T9VdJXouaabXP5r6ra"></p>

- Create Project:
<p align="left"><img src="https://drive.google.com/uc?export=view&id=1B-M_ITUwNsU3nTICGJ1l91aEggJmZx5z"></p>

- Usage:
<p align="left"><img src="https://drive.google.com/uc?export=view&id=1MX0seuhVv7uu4QzMaEXHMyDJRviioSy0"></p>

## Install

The easiest way to install is to use the vscode extension:

- [Marketplace](https://marketplace.visualstudio.com/items?itemName=EdenReich.cpp-console-generator)
- [Repository](https://github.com/edenreich/console-generator-ext-vscode)

Alternatively this could also be achieved in a few manual steps:

1. Create a **CMakeLists.txt** file:

```cmake
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(todo CXX)

# Add the CPM package manager
if(NOT EXISTS "${CMAKE_HOME_DIRECTORY}/cmake/CPM.cmake")
  file(DOWNLOAD https://raw.githubusercontent.com/TheLartians/CPM.cmake/master/cmake/CPM.cmake "${CMAKE_HOME_DIRECTORY}/cmake/CPM.cmake")
endif()

include(cmake/CPM.cmake)

# Add The console-component
CPMAddPackage(
  NAME console
  GITHUB_REPOSITORY edenreich/console-component
  VERSION 1.0.6
  OPTIONS
    "WITH_TESTS Off"
)

# Move the default directory of the executable to bin directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# Collect implementation files of the current project
set(SOURCES_CXX_FILES
    main.cpp
    # add your Implementation files here..
)

# Add the implementation files to the executable
add_executable(${PROJECT_NAME} ${SOURCES_CXX_FILES})

# Add the definition files
include_directories(${CMAKE_BINARY_DIR}/dist/include)

# Link the executable with the library
target_link_libraries(${PROJECT_NAME} console)
```

2. Create a **build** directory and cd into it:

```sh
mkdir build && cd build
```

3. Look at usage for creating commands or use the [console-component-generator](https://github.com/edenreich/console-component-generator) util to generates command files easily.

```sh
curl -sSL https://github.com/edenreich/console-component-generator/releases/download/v1.0.0/console-gen -o console-gen
chmod u+x console-gen && sudo mv console-gen /usr/bin/console-gen
```

4. Build your project:

```sh
cmake .. && make
```

If you are having trouble setting this up, take a look at the examples first.

## Usage

1. Create the application:

```cpp
// main.cpp
#include <console/application.h>

#include "commands/copy_files.h"
#include "commands/hello_world.h"


int main(int argc, char * argv[])
{
    Console::Application app(argc, argv);

    app.setApplicationName("Todo List Application");
    app.setApplicationUsage("./bin/todo [command] [options]");
    app.setApplicationVersion("1.0.0");
    app.setAutoPrintHelp(true);

    app.setApplicationDescription("Todo List Application");

    app.addGlobalOption("--test", "Testing the application", "-t");

    app.addCommand(new CopyFiles);
    app.addCommand(new HelloWorld);

    return app.run();
}
```

2. Create a command definition file:

```cpp
// commands/copy_files.h
#pragma once

#include <console/interfaces/command_interface.h>
#include <console/types/collections.h>

namespace Interfaces = Console::Interfaces;
namespace Types = Console::Types;

/**
 * @name copy:files
 */
class CopyFiles : public Interfaces::CommandInterface
{

public:

    /**
     * Retrieve the name of the command.
     *
     * @return std::string
     */
    std::string getName() override;

    /**
     * Retrieve the description of the command.
     *
     * @return std::string
     */
    std::string getDescription() override;

    /**
     * Retrieve the command options.
     *
     * @return Console::Types::AvailableOptions
     */
    Types::AvailableOptions getOptions() override;

    /**
     * Handle the command.
     *
     * @param Console::Interfaces::InputInterface * input
     * @param Console::Interfaces::OutputInterface * output
     * @return ExitCode
     */
    ExitCode handle(Interfaces::InputInterface * input, Interfaces::OutputInterface * output) override;

};
```

3. Create a command implementation file:

```cpp
// commands/copy_files.cpp
#include "copy_files.h"


/**
 * Retrieve the name of the command.
 *
 * @return std::string
 */
std::string CopyFiles::getName()
{
    return "copy:files";
}

/**
 * Retrieve the description of the command.
 *
 * @return std::string
 */
std::string CopyFiles::getDescription()
{
    return "copy files from <source> to <dist>";
}

/**
 * Retrieve the command options.
 *
 * @return Console::Types::AvailableOptions
 */
Types::AvailableOptions CopyFiles::getOptions()
{
    Types::AvailableOptions options;

    options["-s"] = std::pair<std::string, std::string>("--source", "specific the source");
    options["-d"] = std::pair<std::string, std::string>("--dest", "specific the destination");

    return options;
}

/**
 * Handle the command.
 *
 * @param Console::Interfaces::InputInterface * input
 * @param Console::Interfaces::OutputInterface * output
 * @return ExitCode
 */
ExitCode CopyFiles::handle(Interfaces::InputInterface * input, Interfaces::OutputInterface * output)
{
    if (input->wantsHelp()) {
        output->printCommandHelp(this);
        return ExitCode::NeedHelp;
    }

    if (input->getOption("source").empty() || input->getOption("dest").empty()) {
        output->warning("wrong options..");
        output->printCommandHelp(this);
        return ExitCode::NeedHelp;
    }

    std::string source = input->getOption("source");
    std::string dest = input->getOption("dest");

    output->info("Copying files from %s to %s", source.c_str(), dest.c_str());

    return ExitCode::Ok;
}
```

## Build

Run `cd build && cmake .. -DCMAKE_BUILD_TYPE=Release && cmake --build . --config Release --target install -- -j4`

After building the project all distributed files should be located in `build/dist`.

## Target

This project targets Linux, Windows and MacOS.

## Motivation

Often I find myself having to write the same code over and over again, So I've decided to dedicate my time to building a console application in an OOP way.
After all, all it is needed is a CPP and a Header file per command. Having a dedicated class / object per command makes it easier to maintain.

Because it is a statically linked library I have avoided including external libraries and kept it as simple as possible.

## Contribution

If you find this project interesting or have any suggestions, feel free to send a pull request. I will be more than happy to review it.
