
#pragma once

#include "../../emit/CodeEmitter.h"

enum class AstNodeKind {
    NONE,
    PROGRAM
    // TODO: Add more nodes as they are added
};

class AstNode {
public:
    virtual ~AstNode() {} // virtual destructor
    virtual void emit_code(CodeEmitter &emitter) = 0;

protected:
    AstNodeKind kind = AstNodeKind::NONE;
};
