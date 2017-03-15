cmake_minimum_required(VERSION 3.6)
project(CookieToastCompiler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp
        lexer/CTCLexer.h
        lexer/CTCLexer.cpp
        lexer/Token.cpp
        lexer/Token.h
        lexer/charclassifier.h
        lexer/charclassifier.cpp
        parser/Parser.h
        parser/Parser.cpp
        util/bitmath.h )
add_executable(CookieToastCompiler ${SOURCE_FILES})