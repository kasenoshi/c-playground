#include <vector>
#include <algorithm>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if(k <= 0)
            return;     
        reverse(nums.begin(), nums.end()-k);
        reverse(nums.end()-k, nums.end());
        reverse(nums.begin(), nums.end());
    }
    void rotate2(vector<int>& nums, int k) {
        k = k % nums.size();
        if(k <= 0)
            return;     
        while(k > 0){
            int  back = nums.back();
            nums.pop_back();
            vector<int>::iterator it = nums.begin();
            nums.insert(it, back);
            k--;
        }
    }
};

TEST(ArrayTest, EmptyTest){
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    s.rotate(nums, 0);
    EXPECT_EQ(1, nums[0]); 
    EXPECT_EQ(2, nums[1]); 
}
TEST(ArrayTest, NoramlTest1){
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    s.rotate(nums, 3);
    EXPECT_EQ(5, nums[0]); 
    EXPECT_EQ(6, nums[1]); 
    EXPECT_EQ(7, nums[2]); 
    EXPECT_EQ(1, nums[3]); 
    EXPECT_EQ(2, nums[4]); 
    EXPECT_EQ(3, nums[5]); 
    EXPECT_EQ(4, nums[6]); 
}
TEST(ArrayTest, NoramlTest2){
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    s.rotate(nums, 2);
    EXPECT_EQ(1, nums[0]); 
    EXPECT_EQ(2, nums[1]); 
}
TEST(ArrayTest, NoramlTest3){
    Solution s;
    vector<int> nums;
    nums.push_back(-1);
    s.rotate(nums, 2);
    EXPECT_EQ(-1, nums[0]); 
}
TEST(ArrayTest, NoramlTest4){
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    s.rotate(nums, 3);
    EXPECT_EQ(2, nums[0]); 
    EXPECT_EQ(1, nums[1]); 
}

TEST(ArrayTest, NoramlTest5){
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    s.rotate(nums, 2);
    EXPECT_EQ(5, nums[0]); 
    EXPECT_EQ(6, nums[1]); 
    EXPECT_EQ(1, nums[2]); 
    EXPECT_EQ(2, nums[3]); 
    EXPECT_EQ(3, nums[4]); 
    EXPECT_EQ(4, nums[5]); 
}
int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
