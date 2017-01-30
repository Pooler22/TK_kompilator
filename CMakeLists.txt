cmake_minimum_required(VERSION 3.6)
project(Compiler)

set(CMAKE_CXX_STANDARD 11)

find_package(BISON)
find_package(FLEX)

set(SOURCE_FILES
        emitter.cpp
        error.cpp
        global.hpp
        lexer.l
        main.cpp
        parser.y
        symbol.cpp
        symbol.hpp)


add_executable(Compiler ${SOURCE_FILES})