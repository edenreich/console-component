<p align="left"><img src="https://drive.google.com/uc?export=view&id=1-x4N2CctotfbV9U-m7b8AUjOtXLlH9cs"></p>

# Commandline Parser Library

An easy to use library for building powerful console applications written in C++.

## Todo

- [ ] Implement a method to add command classes references, invoke their handle method and pass the options flags when called

## Usage

1. Create a command definition file:

```
// commands/copy_files.h
#pragma once

#include <console/command.h>
#include <console/types/exit_code.h>


class CopyFiles : public Command
{

public:
    std::string getName() override;

    std::string getDescription() override;

    ExitCode handle(const std::string * options) override;

};
```

2. Create a command implemention file:

```
// commands/copy_files.cpp
#include "copy_files.h"
#include <iostream>


std::string CopyFiles::getName()
{
    return "copy-files";
}


std::string CopyFiles::getDescription()
{
    return "copy files from <source> to <dist>";
}

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

    app.addCommand(new CopyFiles);
    app.addCommand(new HelloWorld);

    app.printHelp();

    return app.run();
}
```


## Build

Run `cd build && cmake .. && cmake --build . --target install`

## Distributed Files

After building the project all distributed files should be located in build/dist

## Target

This project currently targets linux

## Motiviation

Often I find myself have to write the same code over and over again, So I've decided to dedicate my time to build a commandline application in an OOP way.
After all, all it is needed is a CPP and HEADER file per command.
Having dedicated class / object per command makes it easier to maintain.

Because it is statically linked library I have avoided including external libraries and kept it as simple as possible.

## Contributing Guidelines

If you find this project interesting or have any suggestions, feel free to send a pull request. I will be more than happy to review it.
