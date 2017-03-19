#pragma once

enum class ExpressionOperationType {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    MODULO,
    EQUALITY,
    GREATER_THAN,
    LESS_THAN,
    GREATER_EQUALS,
    LESS_EQUALS,
    NOT_EQUALS,
    NOT,
    AND,
    OR,
    XOR,
    ASSIGNMENT,
    NEGATE,
    FUNCTION_CALL,
    OPEN_ROUND_BRACE,
    OPEN_SQUARE_BRACE,
};

static int perform_op(ExpressionOperationType op, int v1, int v2) {
    using opFunc = int(*)(int, int);
    static const opFunc ops[] = {
            [](int a, int b) {return a + b;},
            [](int a, int b) {return a - b;},
            [](int a, int b) {return a * b;},
            [](int a, int b) {return a / b;},
            [](int a, int b) {return a % b;},
            [](int a, int b) {return int(a == b);},
            [](int a, int b) {return int(a > b);},
            [](int a, int b) {return int(a < b);},
            [](int a, int b) {return int(a >= b);},
            [](int a, int b) {return int(a <= b);},
            [](int a, int b) {return int(a != b);}
    };
    return ops[(int)op](v1, v2);
}

static ExpressionOperationType get_operation_type(std::string op) {
    using Type = ExpressionOperationType;
    if (op == "+") return Type::ADD;
    if (op == "-") return Type::SUBTRACT;
    if (op == "*") return Type::MULTIPLY;
    if (op == "/") return Type::DIVIDE;
    if (op == "%") return Type::MODULO;
    if (op == "&&") return Type::AND;
    if (op == "||") return Type::OR;
    if (op == "==") return Type::EQUALITY;
    if (op == ">") return Type::GREATER_THAN;
    if (op == "<") return Type::LESS_THAN;
    if (op == ">=") return Type::GREATER_EQUALS;
    if (op == "<=") return Type::LESS_EQUALS;
    if (op == "!") return Type::NOT;
    if (op == "!=") return Type::NOT_EQUALS;
    if (op == "^") return Type::XOR;
    if (op == "=") return Type::ASSIGNMENT;
    if (op == "~") return Type::NEGATE;
    
    throw std::runtime_error("unrecognized operator: " + op);
}