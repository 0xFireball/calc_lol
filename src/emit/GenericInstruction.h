
#pragma once

#include <string>

enum class InstructionOperation {
    LOAD_VAR,
    JUMP,
    CALL_FUNC,
    RET,
    ADD,
    SUBTRACT,
    XOR,
    OR,
    AND,
    PUSH,
    POP
};

class GenericInstruction {
public:
    GenericInstruction(InstructionOperation instr_operation, std::string instr_operand = "") : operation(instr_operation),
                                                                                          operand(instr_operand) {

    }

private:
    InstructionOperation operation;
    std::string operand;
};

