cmake_minimum_required(VERSION 3.5.1)
project(geometry)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Iinclude")

include_directories(include)

add_library(geometrylib src/circle.cpp)
target_link_libraries(geometrylib m)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

add_executable(geometry src/main.cpp)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

target_link_libraries(geometry geometrylib)