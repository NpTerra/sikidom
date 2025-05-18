cmake_minimum_required(VERSION 3.10.0)
project(sikidom VERSION 0.1.0 LANGUAGES CXX)

file(GLOB_RECURSE PROJECT_SOURCES "./src/*.cpp")
file(GLOB_RECURSE PROJECT_HEADERS "./headers/*.hpp")
file(GLOB_RECURSE PROJECT_TOOLS   "./tools/*.hpp" "./tools/*.h" "./tools/*.cpp" "./tools/*.c")

list(FILTER PROJECT_SOURCES EXCLUDE REGEX ".*main.*.cpp$")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -DTESTINGG -DMEMTRACE")


add_executable(${PROJECT_NAME} src/main.cpp ${PROJECT_SOURCES} ${PROJECT_HEADERS} ${PROJECT_TOOLS})
add_executable(${PROJECT_NAME}_test src/main_test.cpp ${PROJECT_SOURCES} ${PROJECT_HEADERS} ${PROJECT_TOOLS})


include_directories(headers)
include_directories(tools)
