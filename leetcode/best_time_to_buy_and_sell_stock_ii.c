#include <stdio.h>
#include <limits.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
int maxProfit(int* prices, int pricesSize) {
    if(pricesSize <= 0) //empty
        return 0;
    int index = pricesSize - 1;
    int max_price = 0;
    int min_price = INT_MAX;
    int stock = 0;
    int profit = 0;
    
    while(index >= 0){
        int current_price = prices[index];
        if(current_price < max_price && current_price < min_price){
            min_price = current_price;
        }
        else{
            if(min_price != INT_MAX)
                profit += max_price - min_price;
            max_price = current_price;
            min_price = INT_MAX;
        }
        index--;
    }
    if(min_price != INT_MAX)
        profit += max_price - min_price;
    return profit;
}
/* A test case that with empty input. */
static void empty(void **state) {
    (void) state; /* unused */
    int stock[] = {};
    assert_int_equal(maxProfit(stock, 0), 0);
}
static void normal1(void **state) {
    (void) state; /* unused */
    int stock[] = {1, 2, 3};
    assert_int_equal(maxProfit(stock, 3), 2);
}
static void normal2(void **state) {
    (void) state; /* unused */
    int stock[] = {3, 2, 1};
    assert_int_equal(maxProfit(stock, 3), 0);
}
static void normal3(void **state) {
    (void) state; /* unused */
    int stock[] = {3, 2, 1, 3};
    assert_int_equal(maxProfit(stock, 4), 2);
}
int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(empty),
        cmocka_unit_test(normal1),
        cmocka_unit_test(normal2),
        cmocka_unit_test(normal3),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
