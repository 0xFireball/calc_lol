
#pragma once

#include "AstNodeKind.h"
#include "../../emit/CodeEmitter.h"

class AstNode {
public:
    virtual ~AstNode() {} // virtual destructor
    virtual void emit_code(CodeEmitter& emitter) = 0;
    
protected:
    AstNodeKind kind = AstNodeKind::NONE;
};
