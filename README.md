# Commandline Parser Library

An easy to use library for building powerful console applications written in c++.

## Usage

1. Create a command definition file:

```
// commands/copy_files.h
#pragma once

#include <console/command.h>
#include <console/types/exit_code.h>

/**
 * @description copy files from <source> to <dist>
 */
class CopyFiles : public Command
{

public:
    CopyFiles();
    ~CopyFiles();

    ExitCode handle(const char * options[]) override;

};
```

2. Create a command implemention file:

```
// commands/copy_files.cpp
#include "copy_files.h"

CopyFiles::CopyFiles()
{

}

ExitCode CopyFiles::handle(const char * options[])
{
    std::cout << "command copy files was called";
    std::cout << "Options: " << options;

    return ExitCode::Ok;
}

~CopyFiles::CopyFiles()
{
    
}
```

3. Create the application and add the command:

```
// main.cpp
#include "commands/copy_files.h"
#include "commands/hello_world.h"

int main(int argc, char * argv[])
{
    ConsoleApplication app(argc, argv);

    app.setApplicationName("Awesome Application");
    app.setApplicationVersion("1.0");

    app.setApplicationDescription("My awesome application");

    app.addCommand(new CopyFiles);
    app.addCommand(new HelloWorld);

    return app.run();
}
```

## Build

Run `cd build && cmake .. && make`
