#include "../../kernel/types.h"
#include "../../kernel/riscv.h"
#include "../../kernel/defs.h"
#include "../../kernel/param.h"
#include "../../kernel/memlayout.h"
#include "../../kernel/spinlock.h"
#include "../../kernel/proc.h"

int sys_calculate(void) {
    int x, y;
    char op[2] = {0};  
    uint64 op_addr;    
    uint64 result_addr; 

    argint(0, &x);       
    argint(1, &y);        
    argaddr(2, &op_addr); 
    argaddr(3, &result_addr); 

    if (copyin(myproc()->pagetable, op, op_addr, sizeof(op)) < 0) {
        printf("copyin failed: unable to copy operator from user space\n");
        return -1; 
    }

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
        printf("Invalid operator: %c\n", op[0]);
        return -1; 
    }

    if (copyout(myproc()->pagetable, result_addr, (char *)&result, sizeof(result)) < 0) {
        printf("copyout failed: unable to copy result to user space\n");
        return -1; 
    }

    return 0; 
}
