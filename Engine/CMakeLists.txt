cmake_minimum_required(VERSION 3.15)

project(EngiPixi)

find_package(SDL2 REQUIRED)
include_directories(${CMAKE_BINARY_DIR})

set(CMAKE_CXX_STANDARD 17)

add_executable(EngiPixi
        main.cpp
        Engine.h Engine.cpp
        Tile.h Tile.cpp
        Map.h Map.cpp
        EntityComponentSystem.cpp EntityComponentSystem.h
        Components.h
        TextureManager.cpp TextureManager.h
        GameObject.cpp GameObject.h)
target_link_libraries(EngiPixi SDL2 SDL2_image)
