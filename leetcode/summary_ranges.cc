#include "gtest/gtest.h"
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution{
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> v_s;
        vector<int>::iterator it;
        int head = 0, prev = 0;
        string s;
        for(it = nums.begin(); it != nums.end(); it++){
            if(s.empty()){
                s = to_string(*it);
                head = *it;
                prev = *it;
            }
            else if(*it == prev + 1){
                prev = *it;
            }
            else{
                if(head != prev)
                    s += "->" + to_string(prev);
                v_s.push_back(s);
                s = to_string(*it);
                head = *it;
                prev = *it;
            }
        }
        if(head != prev)
            s += "->" + to_string(prev);
        if(! s.empty())
            v_s.push_back(s);
        return v_s;
    }
    string to_string(int n){
        stringstream ss;
        ss << n;
        string s;
        ss >> s;
        return s;
    }
};

TEST(RangeTest, EmptyTest){
    Solution s;
    vector<string> v_s;
    vector<int> nums;
    v_s = s.summaryRanges(nums);
    EXPECT_EQ(true, v_s.empty());
}
TEST(RangeTest, NormalTest1){
    Solution s;
    vector<string> v_s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(15);
    nums.push_back(16);
    nums.push_back(24);
    nums.push_back(28);
    nums.push_back(29);
    nums.push_back(30);
    v_s = s.summaryRanges(nums);
    EXPECT_EQ("1->3", v_s[0]);
    EXPECT_EQ("5->6", v_s[1]);
    EXPECT_EQ("15->16", v_s[2]);
    EXPECT_EQ("24", v_s[3]);
    EXPECT_EQ("28->30", v_s[4]);
}
TEST(RangeTest, NormalTest2){
    Solution s;
    vector<string> v_s;
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(7);
    v_s = s.summaryRanges(nums);
    EXPECT_EQ("0->2", v_s[0]);
    EXPECT_EQ("4->5", v_s[1]);
    EXPECT_EQ("7", v_s[2]);
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
