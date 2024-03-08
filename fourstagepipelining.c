#include <stdio.h>

typedef struct { int opcode, operand1, operand2; } Instruction;
typedef struct { Instruction instruction; int result; } PipelineRegister;

void fetch_stage(int *i, Instruction *inst) {
    (*i)++; inst->opcode = (*i) % 3;
    inst->operand1 = (*i) * 2; inst->operand2 = (*i) * 2 + 1;
}

void decode_stage(Instruction *inst, PipelineRegister *r) { r->instruction = *inst; }
void execute_stage(PipelineRegister *d, PipelineRegister *e) {
    switch (d->instruction.opcode) {
        case 0: e->result = d->instruction.operand1 + d->instruction.operand2; break;
        case 1: e->result = d->instruction.operand1 - d->instruction.operand2; break;
        case 2: e->result = d->instruction.operand1 * d->instruction.operand2; break;
        default: printf("Invalid opcode\n"); break;
    }
}
void writeback_stage(PipelineRegister *e) { printf("Result: %d\n", e->result); }

int main() {
    int i = 0; Instruction inst; PipelineRegister d, e;
    for (int c = 0; c < 5; c++) {
        fetch_stage(&i, &inst); decode_stage(&inst, &d);
        execute_stage(&d, &e); writeback_stage(&e);
        printf("Cycle %d: Instruction Opcode = %d, Operand1 = %d, Operand2 = %d\n",
               c + 1, inst.opcode, inst.operand1, inst.operand2);
    }
    return 0;
}
