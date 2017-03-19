
#include "SyntaxTreeLinearizer.h"

std::unique_ptr<TAISequence> SyntaxTreeLinearizer::linearize_syntax_tree() {
    // TODO: Convert syntax tree to three address instruction program

    return nullptr;
}

std::unique_ptr<TAISequence>
SyntaxTreeLinearizer::linearize_statement_sequence(StatementSequenceNode *stmt_seq) {
    for (auto stmt : stmt_seq->get_sub_nodes()) {

    }
    return nullptr;
}


