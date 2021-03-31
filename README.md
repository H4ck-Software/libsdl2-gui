# Libsdl2-gui

Libsdl2-gui is a C++ library that provides base classes to ease the development of SDL2 applications, avoiding rewriting code to manage events of multiple windows, creating textures from image files, etc.

## Installation

Use the CMake package manager [CPM](https://github.com/cpm-cmake/CPM.cmake) to install libsdl2-gui as a dependency to your project.

```CMake
cmake_minimum_required(VERSION 3.16)

# create project
project(MyProject)

# add executable
add_executable(tests tests.cpp)

# add dependencies
include(cmake/CPM.cmake)
CPMAddPackage("gh:H4ck-Software/libsdl2-gui#main@0.1.0")

# link dependencies
target_link_libraries(tests libsdl2-gui)
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://choosealicense.com/licenses/mit/)
