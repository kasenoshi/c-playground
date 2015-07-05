#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
 // Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };
 
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *current = head;
    struct ListNode *next;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
struct ListNode* createList(struct ListNode* head, int listSize) {
    struct ListNode* p = head;
    int val = 1;
    while(listSize > 0){
        if(p == NULL){
            head = malloc(sizeof(struct ListNode));
            head->val = val;
            head->next = NULL;
            p = head;
            ++val;
        }
        else{
            p->next = malloc(sizeof(struct ListNode));
            p = p->next;
            p->val = val;
            p->next = NULL;
            ++val;
        }
        --listSize;
    }
    return head; 
}
/* A test case that with empty input. */
static void empty(void **state) {
    (void) state; /* unused */
    struct ListNode *head = NULL;
    head = createList(head, 0);
    head = reverseList(head);
    assert_null(head);
}
static void one_element(void **state) {
    (void) state; /* unused */
    struct ListNode *head = NULL;
    head = createList(head, 1);

    head = reverseList(head);
    assert_int_equal(head->val, 1);
    assert_null(head->next);
}
static void two_elements(void **state) {
    (void) state; /* unused */
    struct ListNode *head = NULL;
    head = createList(head, 2);

    head = reverseList(head);
    struct ListNode *p = head;
    assert_int_equal(p->val, 2);
    assert_non_null(p->next);
    p = p->next;
    assert_int_equal(p->val, 1);
    assert_null(p->next);
}
static void three_elements(void **state) {
    (void) state; /* unused */
    struct ListNode *head = NULL;
    head = createList(head, 3);

    head = reverseList(head);
    struct ListNode *p = head;
    assert_int_equal(p->val, 3);
    assert_non_null(p->next);
    p = p->next;
    assert_int_equal(p->val, 2);
    assert_non_null(p->next);
    p = p->next;
    assert_int_equal(p->val, 1);
    assert_null(p->next);
}
int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(empty),
        cmocka_unit_test(one_element),
        cmocka_unit_test(two_elements),
        cmocka_unit_test(three_elements),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
