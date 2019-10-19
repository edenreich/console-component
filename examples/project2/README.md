
# Example 2

In this example we will link with pthreads to leverage async operations.

## Build Steps

1. Change directory to build `cd build`
2. Configure the project by running `cmake ..`
3. Build the project by running `cmake --build . --config Release -- -j4`

The executable will be inside of the `bin` directory.

Let's test that it works, from the root directory of this project just run: `./bin/http`
