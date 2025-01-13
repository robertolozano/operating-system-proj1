#include "../../kernel/types.h"
#include "../../kernel/riscv.h"
#include "../../kernel/defs.h"
#include "../../kernel/param.h"
#include "../../kernel/memlayout.h"
#include "../../kernel/spinlock.h"
#include "../../kernel/proc.h"

int sys_calculate(void) {
    int x, y;
    char op[2];
    uint64 result_addr;

    argint(0, &x);
    argint(1, &y);
    if (argstr(2, op, sizeof(op)) < 0) {
        return -1;
    }
    argaddr(3, &result_addr);

    int result;
    if (op[0] == '+') {
        result = x + y;
    } else if (op[0] == '-') {
        result = x - y;
    } else if (op[0] == '*') {
        result = x * y;
    } else if (op[0] == '/' && y != 0) {
        result = x / y;
    } else {
        return -1;
    }

    if (copyout(myproc()->pagetable, result_addr, (char*)&result, sizeof(result)) < 0) {
        return -1;
    }

    return 0;
}
