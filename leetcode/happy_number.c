#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

int cal(int n){
    int sum = 0;
    while(n){
        int square = n % 10;
        sum += square * square;
        n /= 10;
    }
    return sum;
}
int isHappy(int n) {
    while (n != 1){
        if (n == 4)
            return 0;
        n = cal(n);
    }
    return 1;
}

/* A test case that with empty input. */
static void empty(void **state) {
    (void) state; /* unused */
    assert_true(isHappy(1));
    assert_true(isHappy(989));
    assert_false(isHappy(4));
    assert_false(isHappy(111));
}
int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(empty),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
