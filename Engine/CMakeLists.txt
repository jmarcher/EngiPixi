cmake_minimum_required(VERSION 3.15)

project(EngiPixi)

find_package(SDL2 REQUIRED)
include_directories(${CMAKE_BINARY_DIR})

set(CMAKE_CXX_STANDARD 17)

#add_executable(EngiPixi
#        main.cpp
#        Engine.h Engine.cpp
#        Tile.h Tile.cpp
#        Map.h Map.cpp
#        EntityComponentSystem.cpp EntityComponentSystem.h
#        Components.h
#        TextureManager.cpp TextureManager.h
#        GameObject.cpp GameObject.h Test.cpp Test.h)

file(GLOB source_files
        "*.h"
        "*.cpp"
        )

add_executable(EngiPixi ${source_files} ECS/SpriteComponent.h ECS/TransformComponent.h Math/Vector2D.h Math/Vector2D.cpp Helpers/FpsHelper.cpp Helpers/FpsHelper.h ECS/KeyboardController.h ECS/ColliderComponent.h Collision.h Collision.cpp)

target_link_libraries(EngiPixi SDL2 SDL2_image SDL2_ttf)
