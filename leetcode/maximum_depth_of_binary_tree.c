#include<stdio.h>


/*Definition for a binary tree node.*/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root) {
    if(root == NULL)
        return 0;

    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    else if(root->left == NULL){
        return 1 + maxDepth(root->right);
    }
    else if(root->right == NULL){
        return 1 + maxDepth(root->left);
    }
    else{
        int rightDepth = maxDepth(root->right);
        int leftDepth = maxDepth(root->left);
        return 1 + ((rightDepth > leftDepth)? rightDepth: leftDepth);
    }
}
main(){
    struct TreeNode *head;
    head = malloc(sizeof(struct TreeNode));
    head->left = NULL;
    head->right = malloc(sizeof(struct TreeNode));
    head->right->left = NULL;
    head->right->right = NULL;
    head = NULL;
    printf("%d\n", maxDepth(head));
}
