#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int height(TreeNode *root){
        if(root == NULL)
            return 0;
        int hr = height(root->right);
        int hl = height(root->left);
        if(hr == -1 || hl == -1 || abs(hr - hl) > 1) return -1;
        return max(hr, hl) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};

TEST(TreeTest, EmptyInput){
    Solution s;
    TreeNode *root = NULL;
    EXPECT_EQ(true, s.isBalanced(root));
}
TEST(TreeTest, NormalInput1){
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    EXPECT_EQ(true, s.isBalanced(root));
}
TEST(TreeTest, NormalInput2){
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left= new TreeNode(2);
    EXPECT_EQ(true, s.isBalanced(root));
}
TEST(TreeTest, NormalInput3){
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->right= new TreeNode(2);
    root->left= new TreeNode(3);
    EXPECT_EQ(true, s.isBalanced(root));
}
TEST(TreeTest, NormalInput4){
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->right= new TreeNode(2);
    root->right->right= new TreeNode(3);
    EXPECT_EQ(false, s.isBalanced(root));
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
