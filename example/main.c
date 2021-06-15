#include <stdio.h>
#include "fgn_trace.h"

void func_c(int var_c) {
    FGN_STEP_IN_FUNC();
    FGN_PRINT_INT("var_c",var_c);
    FGN_PRINT_LINE();
    FGN_STEP_OUT_FUNC();
}

void func_b(int var_b) {
    FGN_STEP_IN_FUNC();
    func_c(var_b+1);
    FGN_STEP_OUT_FUNC();
}

void func_a(int var_a) {
    FGN_STEP_IN_FUNC();
    func_b(var_a+1);
    FGN_STEP_OUT_FUNC();
}

int main() {
    FGN_STEP_IN_FUNC();
    func_a(1);
    FGN_STEP_OUT_FUNC();
    return 0;
}