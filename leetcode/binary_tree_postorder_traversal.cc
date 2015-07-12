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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> v;
        TreeNode *prev = NULL;
        if(root)
            s.push(root);
        while(!s.empty()){
            TreeNode *current = s.top();
            // traversal down
            if(!prev || prev->left == current || prev->right == current){
                if(current->left)
                    s.push(current->left);
                else if(current->right)
                    s.push(current->right);
                else{
                    v.push_back(current->val);
                    s.pop();
                }
            }
            // traversal up from left
            else if(prev == current->left){
                if(current->right)
                    s.push(current->right);
                else{
                    v.push_back(current->val);
                    s.pop();
                }
            }
            // traversal up from right
            else if(prev == current->right){
                v.push_back(current->val);
                s.pop();
            }
            prev = current;
        }
        return v;
    }
};

TEST(TreeTest, EmptyInput){
    Solution s;
    EXPECT_EQ(0, s.postorderTraversal(NULL).size());
}
TEST(TreeTest, NormalInput){
    Solution s;

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int> v = s.postorderTraversal(root);
    EXPECT_EQ(3, v.size());
    EXPECT_EQ(3, v[0]);
    EXPECT_EQ(2, v[1]);
    EXPECT_EQ(1, v[2]);
}
TEST(TreeTest, NormalInput2){
    Solution s;

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->left = new TreeNode(2);
    vector<int> v = s.postorderTraversal(root);
    EXPECT_EQ(3, v.size());
    EXPECT_EQ(2, v[0]);
    EXPECT_EQ(3, v[1]);
    EXPECT_EQ(1, v[2]);
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
