#include "gtest/gtest.h"

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *ans = root;
        TreeNode *p1 = root;
        TreeNode *p2 = root;
        if(ans == NULL)
            return NULL;
        while(true){
            if(p->val > p1->val)
                p1 = p1->right;
            else if(p->val != p1->val)
                p1 = p1->left;
            if(q->val > p2->val)
                p2 = p2->right;
            else if(q->val != p2->val)
                p2 = p2->left;
            if(p1 == p2)
                ans = p1;
            else
                break;
        }
        return ans;
    }
};

TEST(TreeTest, EmptyInput){
    Solution s;
    EXPECT_EQ(NULL, s.lowestCommonAncestor(NULL, NULL, NULL));
}
TEST(TreeTest, NormalInput1){
    Solution s;
    TreeNode *head = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left = new TreeNode(1);

    EXPECT_EQ(2, s.lowestCommonAncestor(head, head->right, head->left)->val);
}
TEST(TreeTest, NormalInput2){
    Solution s;
    TreeNode *head = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left = new TreeNode(1);

    EXPECT_EQ(2, s.lowestCommonAncestor(head, head, head->left)->val);
}
TEST(TreeTest, NormalInput3){
    Solution s;
    TreeNode *head = new TreeNode(6);
    head->left = new TreeNode(2);
    head->right = new TreeNode(8);
    head->left->left= new TreeNode(0);
    head->left->right= new TreeNode(4);
    head->right->left= new TreeNode(7);
    head->right->right= new TreeNode(9);
    head->left->left->left= new TreeNode(3);
    head->left->left->right= new TreeNode(5);

    EXPECT_EQ(6, s.lowestCommonAncestor(head, new TreeNode(2), new TreeNode(8))->val);
}
TEST(TreeTest, NormalInput4){
    Solution s;
    TreeNode *head = new TreeNode(6);
    head->left = new TreeNode(2);
    head->right = new TreeNode(8);
    head->left->left= new TreeNode(0);
    head->left->right= new TreeNode(4);
    head->right->left= new TreeNode(7);
    head->right->right= new TreeNode(9);
    head->left->left->left= new TreeNode(3);
    head->left->left->right= new TreeNode(5);

    EXPECT_EQ(2, s.lowestCommonAncestor(head, new TreeNode(2), new TreeNode(4))->val);
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
