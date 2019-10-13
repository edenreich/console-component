
# Example 1

In this example we build a simple todo application.

## Build Steps

1. Change directory to build `cd build`
2. Download the library by running `conan install ..`
3. Configure the project by running `cmake ..`
4. Build the project by running `cmake --build . --config Release -- -j4`

The binary will be inside of `bin` directory.

Let's test that it works, just run: `./bin/todo`
