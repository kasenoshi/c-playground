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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> v;
        bool done = false;
        TreeNode *current = root;
        while(! done){
            if(current){
                s.push(current);
                current = current->left;
            }else{
                if(s.empty()) done = true;
                else{
                    current = s.top();s.pop();
                    v.push_back(current->val);
                    current = current->right;
                }
            }
        }
        return v;
    }
};

TEST(TreeTest, EmptyInput){
    Solution s;
    EXPECT_EQ(0, s.inorderTraversal(NULL).size());
}
TEST(TreeTest, NormalInput){
    Solution s;

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int> v = s.inorderTraversal(root);
    EXPECT_EQ(3, v.size());
    EXPECT_EQ(1, v[0]);
    EXPECT_EQ(3, v[1]);
    EXPECT_EQ(2, v[2]);
}
TEST(TreeTest, NormalInput2){
    Solution s;

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->left= new TreeNode(2);
    vector<int> v = s.inorderTraversal(root);
    EXPECT_EQ(3, v.size());
    EXPECT_EQ(2, v[0]);
    EXPECT_EQ(1, v[1]);
    EXPECT_EQ(3, v[2]);
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
