cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(SDL2_gui VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

include(CPM)

find_package(SDL2 REQUIRED)
find_package(SDL2_gfx REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_library( SDL2_gui SHARED
    "${PROJECT_SOURCE_DIR}/libsdl2-gui/libsdl2-gui.cpp"
    "${PROJECT_SOURCE_DIR}/libsdl2-gui/texture.cpp"
    "${PROJECT_SOURCE_DIR}/libsdl2-gui/window.cpp"
)

add_library(SDL2::GUI ALIAS SDL2_gui)

target_link_libraries( SDL2_gui
    SDL2::GFX
    SDL2::TTF
    SDL2::Core
)

target_include_directories( SDL2_gui
    PUBLIC ${PROJECT_SOURCE_DIR}
    PUBLIC ${SDL2_INCLUDE_DIR}
)
