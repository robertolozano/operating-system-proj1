
// calc-test.c
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "proj1/user/user.h"

int main(int argc, char *argv[]) {
    int res = 0;
    int error_code = 0;
    char op;

    // Test case 1: Addition
    op = '+';
    error_code = calculate(10, 20, &op, &res);
    printf("10 + 20 = %d, error_code = %d\n", res, error_code);

    // Test case 2: Subtraction
    op = '-';
    error_code = calculate(20, 10, &op, &res);
    printf("20 - 10 = %d, error_code = %d\n", res, error_code);

    // Test case 3: Multiplication
    op = '*';
    error_code = calculate(10, 20, &op, &res);
    printf("10 * 20 = %d, error_code = %d\n", res, error_code);

    // Test case 4: Division
    op = '/';
    error_code = calculate(20, 10, &op, &res);
    printf("20 / 10 = %d, error_code = %d\n", res, error_code);

    // Test case 5: Division by zero
    op = '/';
    error_code = calculate(10, 0, &op, &res);
    printf("10 / 0 = %d, error_code = %d\n", res, error_code);

    // Test case 6: Invalid operator
    op = '%';
    error_code = calculate(10, 20, &op, &res);
    printf("10 %% 20 = %d, error_code = %d\n", res, error_code);

    exit(0);
}