cmake_minimum_required(VERSION 3.15)
project(volo)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} main.cpp Game.cpp Game.h)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})