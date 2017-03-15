cmake_minimum_required(VERSION 3.6)
project(CookieToastCompiler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp lexer/ctc_lexer.h lexer/ctc_lexer.cpp lexer/Token.cpp lexer/Token.h lexer/charclassifier.h util/bitmath.h lexer/charclassifier.cpp)
add_executable(CookieToastCompiler ${SOURCE_FILES})