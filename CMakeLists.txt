cmake_minimum_required(VERSION 3.10)

project(libsdl2-gui)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules)

find_package(SDL2 REQUIRED)
find_package(SDL2_gfx REQUIRED)
find_package(SDL2_ttf REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library( ${PROJECT_NAME} 
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/${PROJECT_NAME}.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/texture.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/window.cpp
)

target_link_libraries( ${PROJECT_NAME}
    ${SDL2MAIN_LIBRARY}
    ${SDL2_GFX_LIBRARY}
    ${SDL2_TTF_LIBRARY}
    ${SDL2_LIBRARY}
)

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${SDL2_INCLUDE_DIR}
)
