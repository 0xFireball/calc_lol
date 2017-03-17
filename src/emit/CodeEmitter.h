
#pragma once

enum class InstructionSet {
    PLATFORM_AGNOSTIC,
    TI_Z80
};

class CodeEmitter {
public:
    CodeEmitter(InstructionSet instruction_set) : instr_set(instruction_set) {
    }

private:
    InstructionSet instr_set;
};