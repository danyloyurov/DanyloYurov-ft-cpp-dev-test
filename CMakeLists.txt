cmake_minimum_required(VERSION 2.8)
project(calculator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(INCLUDE
Bookkeeper/include
Calculator/include
Parser/include
FileManager/include
api/include)

set(SOURCE
main.cpp
Bookkeeper/source/Bookkeeper.cpp
Calculator/source/Calculator.cpp
Parser/source/Parser.cpp
FileManager/source/FileManager.cpp
api/source/Helper.cpp)

include_directories(${INCLUDE})

add_executable(${PROJECT_NAME} ${SOURCE})