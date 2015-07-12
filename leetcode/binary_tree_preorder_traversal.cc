#include "gtest/gtest.h"
#include <vector>
#include <stack>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> v;
        if(root != NULL)
            s.push(root);
        while(! s.empty()){
            TreeNode *current = s.top();s.pop();
            v.push_back(current->val);
            if(current->right != NULL)
                s.push(current->right);
            if(current->left != NULL)
                s.push(current->left);
        }
        return v;
    }
};

TEST(TreeTest, EmptyInput){
    Solution s;
    EXPECT_EQ(0, s.preorderTraversal(NULL).size());
}
TEST(TreeTest, NormalInput){
    Solution s;

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int> v = s.preorderTraversal(root);
    EXPECT_EQ(3, v.size());
    EXPECT_EQ(1, v[0]);
    EXPECT_EQ(2, v[1]);
    EXPECT_EQ(3, v[2]);
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
