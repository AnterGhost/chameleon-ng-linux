cmake_minimum_required(VERSION 2.8)
project(chameleon-ng)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++14 -Wall -Wextra -Wpedantic")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -static-libstdc++")

include_directories("include")

file(GLOB_RECURSE SOURCE_FILES src/*.cpp include/*.cpp)

add_library(chameleon-ng SHARED ${SOURCE_FILES})

target_link_libraries(chameleon-ng SDL2 GL)
