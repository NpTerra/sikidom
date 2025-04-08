cmake_minimum_required(VERSION 3.10.0)
project(sikidom VERSION 0.1.0 LANGUAGES CXX)

file(GLOB_RECURSE PROJECT_SOURCES "./src/*.cpp")
file(GLOB_RECURSE PROJECT_HEADERS "./headers/*.hpp")
file(GLOB_RECURSE PROJECT_TOOLS   "./tools/*.hpp" "./tools/*.h" "./tools/*.cpp" "./tools/*.c")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DMEMTRACE")

# manual test build
#add_executable(${PROJECT_NAME}
#    src/main.cpp
#    src/point.cpp
#    headers/point.hpp
#    headers/math2d.hpp
#)

# automatic full build
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS} ${PROJECT_TOOLS})

include_directories(headers)
include_directories(tools)
