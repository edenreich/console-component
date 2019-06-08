# Commandline Parser Library

An easy to use library for building powerful console applications written in C++.

## Todo

- [x] Resolve relative consumer commands directory
- [x] Parse the header files inside of that directory and look for @ notations during compile time save them in std::map.
- [x] When help is called display the results which was collected by the directory parser, something like [command name][\t][command description]
- [ ] Implement a method to add command classes references, invoke their handle method and pass the options flags when called

## Usage

1. Create a command definition file:

```
// commands/copy_files.h
#pragma once

#include <console/command.h>
#include <console/types/exit_code.h>

/**
 * @name copy-files
 * @description copy files from <source> to <dist>
 */
class CopyFiles : public Command
{

public:
    ExitCode handle(const std::string * options);

};
```

2. Create a command implemention file:

```
// commands/copy_files.cpp
#include "copy_files.h"
#include <iostream>

ExitCode CopyFiles::handle(const std::string * options)
{
    std::cout << "command copy files was called";

    return ExitCode::Ok;
}
```

3. Create the application and add the command:

```
// main.cpp
#include <console/application.h>
#include "commands/copy_files.h"
#include "commands/hello_world.h"

int main(int argc, char * argv[])
{
    Application app(argc, argv);

    app.setApplicationName("Todo List Application");
    app.setApplicationUsage("./bin/todo [command] [options]");
    app.setApplicationVersion("1.0");

    app.setApplicationDescription("Todo List Application");

    app.setCommandsDirectoryPath("commands");
    
    app.printHelp();

    // app.addCommand(new CopyFiles);
    // app.addCommand(new HelloWorld);

    return app.run();
}
```

Whenever you compile the program, a parser will look for the @name @description anotation and generate the help file for you.

## Build

Run `cd build && cmake .. && cmake --build . --target install`

## Distributed Files

After building the project all distributed files should be located in build/dist

## Target

This project currently targets linux

## Motiviation

Often I find myself have to write the same code over and over again, so I thought it would be nice to parse the docblocks of each command,
So the project could be maintained easily. After all, all it is needed is a CPP and HEADER file per command.
Having dedicated class / object per command makes it easier to maintain.
Because it is statically linked library I have avoided including external libraries and kept it as simple as possible.
