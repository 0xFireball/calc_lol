
#pragma once

enum class InstructionOperation {
    LOAD_VAR,
    JUMP,
    CALL_FUNC,
    ADD,
    SUBTRACT,
    XOR,
    OR,
    AND
};

class GenericInstruction {
public:
    GenericInstruction(InstructionOperation instr_operation, std::string instr_operand) : operation(instr_operation),
                                                                                          operand(instr_operand) {

    }

private:
    InstructionOperation operation;
    string operand;
};

