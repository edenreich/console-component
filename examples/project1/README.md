
# Example 1

In this example we build a simple todo application.

## Build Steps

1. Change directory to build `cd build`
2. Configure the project by running `cmake ..`
3. Build the project by running `cmake --build . --config Release -- -j4`

The executable will be inside of `bin` directory.

Let's test that it works, from the root directory of this project just run: `./bin/todo`
