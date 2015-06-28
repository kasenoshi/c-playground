#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
int hammingWeight(uint32_t n) {
    int num_bits = 0;
    while(n > 0){
        num_bits++;
        n &= n - 1;
    }
    return num_bits;
}
/* A test case that with empty input. */
static void empty(void **state) {
    (void) state; /* unused */
    uint32_t n = 0x0;
    assert_int_equal(hammingWeight(n), 0);
}
static void normal(void **state) {
    (void) state; /* unused */
    uint32_t n = 0xFFFFFFFF;
    assert_int_equal(hammingWeight(n), 32);
}
int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(empty),
        cmocka_unit_test(normal),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
