#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
int singleNumber(int* nums, int numsSize) {
    int index = 0;
    int ones = 0;
    int twos = 0;
    int not_threes = 0;
    while(index < numsSize){
        twos |= nums[index] & ones;
        ones ^= nums[index];
        not_threes = ~(twos & ones);
        twos &= not_threes;
        ones &= not_threes;
        ++index;
    }
    return ones;
}

/* A test case that with empty input. */
static void normal(void **state) {
    (void) state; /* unused */
    int array[] = {4,1,1,1};
    assert_int_equal(singleNumber(array, 4), 4);
}
int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(normal),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
