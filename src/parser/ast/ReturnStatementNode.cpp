
#include "ReturnStatementNode.h"

void ReturnStatementNode::emit_code(CodeEmitter &emitter) {
    // TODO: Push return value
    emitter.append_instruction(GenericInstruction(InstructionOperation::PUSH, "SOMETHING_NOT_IMPLEMENTED_TO_PUSH_RETURN_VALUE"));
    // TODO: ???
    emitter.append_instruction(GenericInstruction(InstructionOperation::RET));
}
