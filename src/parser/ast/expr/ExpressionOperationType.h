#pragma once

enum class ExpressionOperationType {
    Add,
    Subtract,
    Multiply,
    Divide,
    Modulo,
    Assignment,
    Equals,
    GreaterThan,
    LessThan,
    GreaterEquals,
    LessEquals,
    NotEquals,
    Not,
    And,
    Or,
    Negate,
    FunctionCall,
    OpenRoundBrace,
    OpenSquareBrace,
    Xor,
};