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

static ExpressionOperationType getOpType(std::string op) {
    using Type = ExpressionOperationType;
    if (op == "+") return Type::Add;
    if (op == "-") return Type::Subtract;
    if (op == "*") return Type::Multiply;
    if (op == "/") return Type::Divide;
    if (op == "%") return Type::Modulo;
    if (op == "&&") return Type::And;
    if (op == "||") return Type::Or;
    throw std::runtime_error("bad operator: " + op);
}