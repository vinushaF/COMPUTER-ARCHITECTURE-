#include <stdio.h>

typedef struct { int opcode, operand1, operand2; } Instruction;

void fetch_stage(int *ic, Instruction *ib) {
    (*ic)++; ib->opcode = (*ic) % 3;
    ib->operand1 = (*ic) * 2; ib->operand2 = (*ic) * 2 + 1;
}

void execute_stage(Instruction *ib, int *res) {
    switch (ib->opcode) {
        case 0: *res = ib->operand1 + ib->operand2; break;
        case 1: *res = ib->operand1 - ib->operand2; break;
        case 2: *res = ib->operand1 * ib->operand2; break;
        default: printf("Invalid opcode\n"); break;
    }
}

int main() {
    int ic = 0, res;
    Instruction ci;
    for (int i = 0; i < 5; i++) {
        fetch_stage(&ic, &ci); execute_stage(&ci, &res);
        printf("Cycle %d: Result = %d\n", i + 1, res);
    }
    return 0;
}
