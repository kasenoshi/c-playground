#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
    public:
        int minDepth(TreeNode *root){
            if(root == NULL)
                return 0;
            if(root->left == NULL && root->right == NULL)
                return 1;
            if(root->left == NULL)
                return minDepth(root->right) + 1;
            if(root->right == NULL)
                return minDepth(root->left) + 1;
            return min(minDepth(root->right), minDepth(root->left)) + 1;
        }
};

TEST(MinDepthTest, EmptyInput){
    Solution solution;
    EXPECT_EQ(0, solution.minDepth(NULL));
}

TEST(MinDepthTest, NormalInput1){
    Solution solution;
    TreeNode *root = new TreeNode(0);
    EXPECT_EQ(1, solution.minDepth(root));
}
TEST(MinDepthTest, NormalInput2){
    Solution solution;
    TreeNode *root = new TreeNode(0);
    root->right = new TreeNode(1);
    EXPECT_EQ(2, solution.minDepth(root));
}
TEST(MinDepthTest, NormalInput3){
    Solution solution;
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(1);
    EXPECT_EQ(2, solution.minDepth(root));
}
TEST(MinDepthTest, NormalInput4){
    Solution solution;
    TreeNode *root = new TreeNode(0);
    root->left  = new TreeNode(1);
    root->right = new TreeNode(2);
    EXPECT_EQ(2, solution.minDepth(root));
}
int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
