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

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;
    struct ListNode *head = NULL;
    struct ListNode *prev = NULL;
    
    if(p1 == NULL)
        return p2;
    if(p2 == NULL)
        return p1;
        
    while(p1 != NULL && p2 != NULL){
        if(p1->val < p2->val){
            if(head == NULL){
                head = p1;
                prev = p1;
                p1 = p1->next;
            }
            else{
                prev->next = p1;
                prev = p1;
                p1 = p1->next;
            }
        }
        else{
            if(head == NULL){
                head = p2;
                prev = p2;
                p2 = p2->next;
            }
            else{
                prev->next = p2;
                prev = p2;
                p2 = p2->next;
            }
        }
    }
    if(p1 == NULL)
        prev->next = p2;
    else
        prev->next = p1;
        
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
    struct ListNode *l1 = NULL;
    struct ListNode *l2 = NULL;
    l1 = mergeTwoLists(l1, l2);
    assert_null(l1);
}
static void one_element(void **state) {
    (void) state; /* unused */
    struct ListNode *l1 = NULL;
    int a1[] = {1};
    struct ListNode *l2 = NULL;
    int a2[] = {2};
    l1 = createList(l1, a1, 1);
    l2 = createList(l2, a2, 1);

    struct ListNode *p = mergeTwoLists(l1, l2);
    assert_int_equal(p->val, 1);
    p = p->next;
    assert_int_equal(p->val, 2);
    p = p->next;
    assert_null(p);
}
static void two_elements(void **state) {
    (void) state; /* unused */
    struct ListNode *l1 = NULL;
    int a1[] = {1, 3};
    struct ListNode *l2 = NULL;
    int a2[] = {2, 4};
    l1 = createList(l1, a1, 2);
    l2 = createList(l2, a2, 2);

    struct ListNode *p = mergeTwoLists(l1, l2);
    assert_int_equal(p->val, 1);
    p = p->next;
    assert_int_equal(p->val, 2);
    p = p->next;
    assert_int_equal(p->val, 3);
    p = p->next;
    assert_int_equal(p->val, 4);
    p = p->next;
    assert_null(p);
}
int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(empty),
        cmocka_unit_test(one_element),
        cmocka_unit_test(two_elements),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
