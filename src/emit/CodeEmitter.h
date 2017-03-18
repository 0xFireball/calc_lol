
#pragma once

#include <memory>

class ProgramNode;

enum class InstructionSet {
    PLATFORM_AGNOSTIC,
    TI_Z80
};

class CodeEmitter {
public:
    CodeEmitter(InstructionSet instruction_set, std::shared_ptr <ProgramNode> syntax_tree) : instr_set(instruction_set),
                                                                                             ast(syntax_tree) {
    }

private:
    InstructionSet instr_set;
    std::shared_ptr <ProgramNode> ast;
};