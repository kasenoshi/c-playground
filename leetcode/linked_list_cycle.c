#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

int hasCycle(struct ListNode *head) {
    struct ListNode *tortoise = head;
    struct ListNode *hare = head;
    while(1){
        if(hare == NULL)
            return 0;
        hare = hare->next;
        if(hare == NULL)
            return 0;
        hare = hare->next;
        tortoise = tortoise->next;
        if(hare != NULL && hare->val == tortoise->val)
            return 1;
    }
}
/* A test case that with empty input. */
static void empty(void **state) {
    (void) state; /* unused */
    struct ListNode *head = NULL;
    assert_int_equal(hasCycle(head), 0);
}
static void normal(void **state) {
    (void) state; /* unused */
    struct ListNode *head = malloc(sizeof(struct ListNode));
    head->val = 0;
    head->next = malloc(sizeof(struct ListNode));
    head->next->val = 1;
    head->next->next = head;
    assert_int_equal(hasCycle(head), 1);
}
static void abnormal(void **state) {
    (void) state; /* unused */
    struct ListNode *head = malloc(sizeof(struct ListNode));
    head->val = 0;
    head->next = malloc(sizeof(struct ListNode));
    head->next->val = 1;
    head->next->next = NULL;
    assert_int_equal(hasCycle(head), 0);
}
int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(empty),
        cmocka_unit_test(normal),
        cmocka_unit_test(abnormal),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
