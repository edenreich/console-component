
# Example 1

In this example we build a simple todo application.

## Build Steps

1. First let's build the library, **in the root directory** run `cd build && cmake .. && cmake --build . --target install`
2. Lastly let's build this project and link the library, from **this directory** run `cd build && cmake .. && cmake --build . --target install`

The binary will be inside of `bin` directory.

Let's test that it works, just run: `./bin/todo`
