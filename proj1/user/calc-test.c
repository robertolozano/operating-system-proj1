// calc-test.c
// #include "kernel/types.h"
// #include "kernel/stat.h"
// #include "user/user.h"
// int main(int argc, char *argv[]) {
//  int res = 0;
//  char op = '-';
//  int error_code = calculate(40, 20, &op, &res);
//  printf("%d, %d\n", res, error_code);
//  exit(0);
// }


#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void test_calculate(int x, int y, char op, int expected_res, int expect_error) {
    int res = 0;
    int error_code = calculate(x, y, &op, &res);

    if (error_code == expect_error && res == expected_res) {
        printf("PASS: calculate(%d, %d, '%c') = %d, error_code = %d\n", x, y, op, res, error_code);
    } else {
        printf("FAIL: calculate(%d, %d, '%c') => res = %d (expected %d), error_code = %d (expected %d)\n",
               x, y, op, res, expected_res, error_code, expect_error);
    }
}

int main(int argc, char *argv[]) {
    printf("Starting calculate tests...\n");

    // Basic operations
    test_calculate(10, 20, '+', 30, 0); // 10 + 20 = 30
    test_calculate(20, 10, '-', 10, 0); // 20 - 10 = 10
    test_calculate(10, 20, '*', 200, 0); // 10 * 20 = 200
    test_calculate(20, 10, '/', 2, 0); // 20 / 10 = 2

    // Division by zero
    test_calculate(10, 0, '/', 0, -1); // 10 / 0 = error

    // Invalid operator
    test_calculate(10, 20, '%', 0, -1); // Invalid operator '%'

    printf("All tests completed.\n");
    exit(0);
}
