
#pragma once

#include <memory>
#include <vector>
#include "GenericInstruction.h"

class ProgramNode;

enum class InstructionSet {
    PLATFORM_AGNOSTIC,
    TI_Z80
};

class CodeEmitter {
public:
    CodeEmitter(InstructionSet instruction_set, std::shared_ptr<ProgramNode> syntax_tree) : instr_set(instruction_set),
                                                                                            ast(syntax_tree) {
    }

    void append_instruction(GenericInstruction instr) {
        instructions.push_back(instr);
    }

    std::shared_ptr<ProgramNode> get_syntax_tree() { return ast; }

private:
    InstructionSet instr_set;
    std::shared_ptr<ProgramNode> ast;
    std::vector<GenericInstruction> instructions;
};