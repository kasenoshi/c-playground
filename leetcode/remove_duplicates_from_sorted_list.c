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
 
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *current = head;
    struct ListNode *next = NULL;
    while(current != NULL){
        next = current->next;
        if(prev == NULL || prev->val != current->val){
            prev = current;
            current = next;
        }
        else{
            free(current);
            prev->next = next;
            current = next;
        }
    }
    return head;
}
struct ListNode* createList(struct ListNode* head, int vals[], int listSize) {
    struct ListNode* p = head;
    int index = 0;
    while(index < listSize){
        if(p == NULL){
            head = malloc(sizeof(struct ListNode));
            head->val = vals[index];
            head->next = NULL;
            p = head;
        }
        else{
            p->next = malloc(sizeof(struct ListNode));
            p = p->next;
            p->val = vals[index];
            p->next = NULL;
        }
        ++index;
    }
    return head; 
}
/* A test case that with empty input. */
static void empty(void **state) {
    (void) state; /* unused */
    struct ListNode *head = NULL;
    int vals[] = {};
    head = createList(head, vals, 0);
    head = deleteDuplicates(head);
    assert_null(head);
}
static void one_element(void **state) {
    (void) state; /* unused */
    struct ListNode *head = NULL;
    int vals[] = {1};
    head = createList(head, vals, 1);
    head = deleteDuplicates(head);
    struct ListNode *p = head;
    assert_int_equal(p->val, 1);
    assert_null(p->next);
}
static void two_elements(void **state) {
    (void) state; /* unused */
    struct ListNode *head = NULL;
    int vals[] = {1, 1};
    head = createList(head, vals, 2);
    head = deleteDuplicates(head);
    struct ListNode *p = head;
    assert_int_equal(p->val, 1);
    assert_null(p->next);
}
static void three_elements(void **state) {
    (void) state; /* unused */
    struct ListNode *head = NULL;
    int vals[] = {1, 2, 2};
    head = createList(head, vals, 3);
    head = deleteDuplicates(head);
    struct ListNode *p = head;
    assert_int_equal(p->val, 1);
    assert_non_null(p->next);
    p = p->next;
    assert_int_equal(p->val, 2);
    assert_null(p->next);
}
static void five_elements(void **state) {
    (void) state; /* unused */
    struct ListNode *head = NULL;
    int vals[] = {1, 1, 2, 3, 3};
    head = createList(head, vals, 5);
    head = deleteDuplicates(head);
    struct ListNode *p = head;
    assert_int_equal(p->val, 1);
    assert_non_null(p->next);
    p = p->next;
    assert_int_equal(p->val, 2);
    assert_non_null(p->next);
    p = p->next;
    assert_int_equal(p->val, 3);
    assert_null(p->next);
}
int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(empty),
        cmocka_unit_test(one_element),
        cmocka_unit_test(two_elements),
        cmocka_unit_test(three_elements),
        cmocka_unit_test(five_elements),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
