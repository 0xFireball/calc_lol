cmake_minimum_required(VERSION 3.6)
project(CookieToastCompiler)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_CXX_STANDARD 14)

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
        parser/ast/AstNode.cpp parser/ast/AstNode.h emit/CodeEmitter.cpp emit/CodeEmitter.h parser/ast/StatementSequenceNode.cpp parser/ast/StatementSequenceNode.h parser/ast/ProgramNode.h parser/expressions/ExpressionParser.cpp parser/expressions/ExpressionParser.h parser/ast/ExpressionNode.cpp parser/ast/ExpressionNode.h util/NotImplementedException.h parser/ast/expr/BinaryOperationNode.h parser/ast/expr/UnaryOperationNode.h parser/ast/VariableAssignmentNode.cpp parser/ast/VariableAssignmentNode.h)
add_executable(CookieToastCompiler ${SOURCE_FILES})
