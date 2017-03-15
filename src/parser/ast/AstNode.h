
#pragma once

#include "../../emit/CodeEmitter.h"

class AstNode {
public:
    virtual void emit_code(CodeEmitter emitter);
};
