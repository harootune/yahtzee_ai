cmake_minimum_required(VERSION 2.8.9)
project(yahtzee)

include_directories(src)

set(MAIN main/main.cpp)
file(GLOB SOURCES "src/*.cpp")
list(APPEND SOURCES ${MAIN})
list(APPEND FLAGS "-Wall" "-std=c++0x" "-stdlib=libc++" "-O2")

add_executable(ytz ${SOURCES})
target_compile_options(ytz PUBLIC ${FLAGS})
