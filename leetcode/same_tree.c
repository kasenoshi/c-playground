#include<stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p == NULL && q == NULL){
        return 1;
    }
    else if(p != NULL && q != NULL){
        if(p->val == q->val){
            return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
        }
    }
    return 0;
}
/* A test case that does nothing and succeeds. */
static void empty_tree(void **state) {
    (void) state; /* unused */
    struct TreeNode *p = NULL;
    struct TreeNode *q = NULL;
    assert_true(isSameTree(p, q));
}
static void same_tree(void **state) {
    (void) state; /* unused */
    struct TreeNode *p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    p->val = 1;
    p->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    p->left->val = 2;
    p->left->right = NULL;
    p->left->left= NULL;
    p->right = NULL;
    struct TreeNode *q = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    q->val = 1;
    q->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    q->left->val = 2;
    q->left->right = NULL;
    q->left->left= NULL;
    q->right = NULL;
    assert_true(isSameTree(p, q));
}
static void different_tree(void **state) {
    (void) state; /* unused */
    struct TreeNode *p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    p->val = 1;
    p->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    p->left->val = 1;
    p->left->right = NULL;
    p->left->left= NULL;
    p->right = NULL;
    struct TreeNode *q = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    q->val = 1;
    q->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    q->left->val = 2;
    q->left->right = NULL;
    q->left->left= NULL;
    q->right = NULL;
    assert_false(isSameTree(p, q));
}
int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(empty_tree),
        cmocka_unit_test(same_tree),
        cmocka_unit_test(different_tree),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
