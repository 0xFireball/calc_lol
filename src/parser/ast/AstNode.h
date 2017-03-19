
#pragma once

#include "../../emit/CodeEmitter.h"

enum class AstNodeKind {
    NONE = 1 << 0,
    PROGRAM = 1 << 1,
    STATEMENT_SEQUENCE = 1 << 2,
    CONDITIONAL = 1 << 3,
    LOOP = 1 << 4,
    MISC = 1 << 31
    // TODO: Add more nodes as they are needed
};

class AstNode {
public:
    AstNode(AstNodeKind ast_node_kind) : kind(ast_node_kind) {}

    AstNode() : AstNode(AstNodeKind::MISC) {}


    virtual ~AstNode() {} // virtual destructor
    virtual void emit_code(CodeEmitter &emitter) = 0;

protected:
    AstNodeKind kind;
};
