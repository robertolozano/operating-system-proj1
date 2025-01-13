#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "proj1/user/user.h"

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
    test_calculate(10, 20, '+', 30, 0); 
    test_calculate(20, 10, '-', 10, 0); 
    test_calculate(10, 20, '*', 200, 0); 
    test_calculate(20, 10, '/', 2, 0); 

    // Division by zero
    test_calculate(10, 0, '/', 0, -1);

    // Invalid operator
    test_calculate(10, 20, '%', 0, -1); 

    printf("All tests completed.\n");
    exit(0);
}
