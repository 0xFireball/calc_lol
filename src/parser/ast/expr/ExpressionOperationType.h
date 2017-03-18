#pragma once

enum class ExpressionOperationType {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    MODULO,
    ASSIGNMENT,
    EQUALS,
    GREATER_THAN,
    LESS_THAN,
    GREATER_EQUALS,
    LESS_EQUALS,
    NOT_EQUALS,
    NOT,
    AND,
    OR,
    XOR,
    NEGATE,
    FUNCTION_CALL,
    OPEN_ROUND_BRACE,
    OPEN_SQUARE_BRACE,
};

static ExpressionOperationType get_operation_type(std::string op) {
    using Type = ExpressionOperationType;
    if (op == "+") return Type::ADD;
    if (op == "-") return Type::SUBTRACT;
    if (op == "*") return Type::MULTIPLY;
    if (op == "/") return Type::DIVIDE;
    if (op == "%") return Type::MODULO;
    if (op == "&&") return Type::AND;
    if (op == "||") return Type::OR;
    throw std::runtime_error("unrecognized operator: " + op);
}