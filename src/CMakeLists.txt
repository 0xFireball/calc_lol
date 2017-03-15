cmake_minimum_required(VERSION 3.6)
project(CookieToastCompiler)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
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
        util/bitmath.h
        parser/ast/AstNode.cpp parser/ast/AstNode.h emit/CodeEmitter.cpp emit/CodeEmitter.h)
add_executable(CookieToastCompiler ${SOURCE_FILES})
