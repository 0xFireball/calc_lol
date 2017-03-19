
#pragma once

#include "../parser/ast/ProgramNode.h"
#include "tai/TAISequence.h"

class SyntaxTreeLinearizer {
public:
    SyntaxTreeLinearizer(CodeEmitter* code_emitter) : emitter(code_emitter) {
    }

    std::unique_ptr<TAISequence> linearize_syntax_tree();

protected:

    std::unique_ptr<TAISequence> linearize_statement_sequence(std::unique_ptr<StatementSequenceNode> stmt_seq);

private:
    CodeEmitter *emitter;
};
