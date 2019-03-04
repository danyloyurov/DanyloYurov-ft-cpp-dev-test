cmake_minimum_required(VERSION 2.8)
project(tcalc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(INCLUDE
bookkeeper/include
calculator/include
parser/include
api/include)

set(SOURCE
main.cpp
bookkeeper/source/bookkeeper.cpp
calculator/source/calculator.cpp
parser/source/parser.cpp
api/source/helper.cpp
)

include_directories(${INCLUDE})

add_executable(${PROJECT_NAME} ${SOURCE})
