cmake_minimum_required(VERSION 3.5.1)
project(geometry)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Iinclude")

include_directories(include)
find_package(GTest REQUIRED)
include_directories(thirdparty)

add_library(geometrylib src/circle.cpp)
target_link_libraries(geometrylib m)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

add_executable(my_test test.cpp)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

target_link_libraries(my_test ${GTEST_LIBRARIES})

add_executable(geometry src/main.cpp)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

target_link_libraries(geometry geometrylib)