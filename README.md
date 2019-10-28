<p>
  <a href="https://github.com/edenreich/console-component"><img alt="GitHub Actions status" src="https://github.com/edenreich/console-component/workflows/build/badge.svg"></a>
</p>

# Console Component

An easy to use component for building powerful console applications written in C++.

- [Console Component](#Console-Component)
    - [Preview](#Preview)
    - [Install](#Install)
    - [Usage](#Usage)
    - [Build](#Build)
    - [Target](#Target)
    - [Motiviation](#Motiviation)
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

Alternative this could also be achieved in few manual steps:

1. First let's download the CPM script 

```sh 
    mkdir -p cmake && wget -O cmake/CPM.cmake https://raw.githubusercontent.com/TheLartians/CPM/master/cmake/CPM.cmake
```

2. Then include this script in your CMake file:

```cmake
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(my_cli CXX)

# Add The CPM Script
include(cmake/CPM.cmake)

# Add The console-component
CPMAddPackage(
  NAME console
  GITHUB_REPOSITORY edenreich/console-component
  VERSION 1.0.2
  OPTIONS
    "WITH_TESTS Off"
)
```

3. Create a directory called commands, there you would store all your command objects (see usage on how to create a command).

4. Lastly link your executable with the console-component like this: `target_link_libraries(${PROJECT_NAME} console)`

If you having trouble setting this up, take a look on the a examples first.

## Usage

1. Create a command definition file:

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

1. Create a command implemention file:

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

3. Create the application and add the command:

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


## Build

Run `cd build && cmake .. -DCMAKE_BUILD_TYPE=Release && cmake --build . --config Release --target install -- -j4`

After building the project all distributed files should be located in `build/dist`.

## Target

This project targets Linux, Windows and macOS

## Motiviation

Often I find myself have to write the same code over and over again, So I've decided to dedicate my time to build a console application in an OOP way.
After all, all it is needed is a CPP and HEADER file per command.
Having dedicated class / object per command makes it easier to maintain.

Because it is statically linked library I have avoided including external libraries and kept it as simple as possible.

## Contribution

If you find this project interesting or have any suggestions, feel free to send a pull request. I will be more than happy to review it.
