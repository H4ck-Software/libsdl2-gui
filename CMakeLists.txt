cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(sdl2-gui VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

include(CPM)

find_package(SDL2 REQUIRED)
find_package(SDL2_gfx REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_library( sdl2-gui SHARED
    "${PROJECT_SOURCE_DIR}/libsdl2-gui/libsdl2-gui.cpp"
    "${PROJECT_SOURCE_DIR}/libsdl2-gui/texture.cpp"
    "${PROJECT_SOURCE_DIR}/libsdl2-gui/window.cpp"
)

target_link_libraries( sdl2-gui
    ${SDL2MAIN_LIBRARY}
    ${SDL2_GFX_LIBRARY}
    ${SDL2_TTF_LIBRARY}
    ${SDL2_LIBRARY}
)

target_include_directories( sdl2-gui
    PUBLIC ${PROJECT_SOURCE_DIR}
    PUBLIC ${SDL2_INCLUDE_DIR}
)
