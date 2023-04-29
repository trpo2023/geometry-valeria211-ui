cmake_minimum_required(VERSION 3.5.1)
project(geometry)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Igeometry-valeria211-ui -Iinclude -Ithirdparty")

include_directories(include)
include_directories(thirdparty)

add_library(geometrylib src/circle.cpp)

target_link_libraries(geometrylib m)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/build)

add_executable(test_app test/test.cpp test/main.cpp)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

target_link_libraries(test_app geometrylib)

add_executable(geometry src/main.cpp)

set(CMAKE_MODULE_PATH${PROJECT_SOURCE_DIR}/build)

target_link_libraries(geometry geometrylib)