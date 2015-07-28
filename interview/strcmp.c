#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
int strcmp(char str1[], char str2[]) {
    int i = 0;
    while(str1[i] == str2[i]){
        if (str1[i] == '\0')
            return 0;
        ++i;
    }
    return (str1[i] > str2[i])? 1: -1;
}
/* A test case that with empty input. */
static void empty(void **state) {
    (void) state; /* unused */
    assert_int_equal(strcmp("", ""), 0);
}
static void normal(void **state) {
    (void) state; /* unused */
    assert_int_equal(strcmp("abcd", "abcd"), 0);
}
static void normal2(void **state) {
    (void) state; /* unused */
    assert_int_equal(strcmp("abc", "abcd"), -1);
}
static void normal3(void **state) {
    (void) state; /* unused */
    assert_int_equal(strcmp("abcd", "abcc"), 1);
}
int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(empty),
        cmocka_unit_test(normal),
        cmocka_unit_test(normal2),
        cmocka_unit_test(normal3),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
