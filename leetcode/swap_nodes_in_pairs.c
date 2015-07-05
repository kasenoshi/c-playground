#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *p1, *p2;
    p1 = head;
    while(p1 != NULL){
        if(p1->next != NULL){
            if(p1 == head){
                head = p1->next;
                p1->next = head->next;
                head->next = p1;
                p2 = p1;
                p1 = p1->next;
            }
            else{
                p2->next = p1->next;
                p1->next = p2->next->next;
                p2->next->next = p1;
                p2 = p1;
                p1 = p1->next;
            }
        }
        else{
            break;
        }
    }
    return head;
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
    head = swapPairs(head);
    assert_null(head);
}
static void one_element(void **state) {
    (void) state; /* unused */
    struct ListNode *head = NULL;
    head = createList(head, 1);

    head = swapPairs(head);
    assert_int_equal(head->val, 1);
    assert_null(head->next);
}
static void two_elements(void **state) {
    (void) state; /* unused */
    struct ListNode *head = NULL;
    head = createList(head, 2);

    head = swapPairs(head);
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

    head = swapPairs(head);
    struct ListNode *p = head;

    assert_int_equal(p->val, 2);
    assert_non_null(p->next);
    p = p->next;
    assert_int_equal(p->val, 1);
    assert_non_null(p->next);
    p = p->next;
    assert_int_equal(p->val, 3);
    assert_null(p->next);
}
static void four_elements(void **state) {
    (void) state; /* unused */
    struct ListNode *head = NULL;
    head = createList(head, 4);

    head = swapPairs(head);
    struct ListNode *p = head;

    assert_int_equal(p->val, 2);
    assert_non_null(p->next);
    p = p->next;
    assert_int_equal(p->val, 1);
    assert_non_null(p->next);
    p = p->next;
    assert_int_equal(p->val, 4);
    assert_non_null(p->next);
    p = p->next;
    assert_int_equal(p->val, 3);
    assert_null(p->next);
}
static void five_elements(void **state) {
    (void) state; /* unused */
    struct ListNode *head = NULL;
    head = createList(head, 5);

    head = swapPairs(head);
    struct ListNode *p = head;

    assert_int_equal(p->val, 2);
    assert_non_null(p->next);
    p = p->next;
    assert_int_equal(p->val, 1);
    assert_non_null(p->next);
    p = p->next;
    assert_int_equal(p->val, 4);
    assert_non_null(p->next);
    p = p->next;
    assert_int_equal(p->val, 3);
    assert_non_null(p->next);
    p = p->next;
    assert_int_equal(p->val, 5);
    assert_null(p->next);
}
int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(empty),
        cmocka_unit_test(one_element),
        cmocka_unit_test(two_elements),
        cmocka_unit_test(three_elements),
        cmocka_unit_test(four_elements),
        cmocka_unit_test(five_elements),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
