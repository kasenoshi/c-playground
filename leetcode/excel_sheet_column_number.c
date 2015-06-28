#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
int titleToNumber(char* s) {
    int num = 0;
    while(*s != '\0'){
        num = num * 26 + *s - 'A' + 1;
        s++;
    }
    return num;
}
/* A test case that with empty input. */
static void empty(void **state) {
    (void) state; /* unused */
    char *s = "";
    assert_int_equal(titleToNumber(s), 0);
}
static void normal(void **state) {
    (void) state; /* unused */
    char *s = "AZ";
    assert_int_equal(titleToNumber(s), 52);
}
int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(empty),
        cmocka_unit_test(normal),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
