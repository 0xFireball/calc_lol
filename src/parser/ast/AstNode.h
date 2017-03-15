
#pragma once

#include "AstNodeKind.h"
#include "../../emit/CodeEmitter.h"

class AstNode {
public:
    virtual void emit_code(CodeEmitter emitter);
protected:
    AstNodeKind kind = AstNodeKind::NONE;
};
