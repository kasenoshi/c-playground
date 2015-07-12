#include "gtest/gtest.h"
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        vector<int>::iterator it;
        map<int, int> m;
        int max_num;
        int max_count = 0;
        for(it = nums.begin(); it != nums.end(); it++){
            if(m[*it])
                m[*it]++;
            else
                m[*it] = 1;
            if(m[*it] > max_count){
                max_num = *it;
                max_count = m[*it];
            }
        }
        return max_num;
    }
};

TEST(ElementTest, NormalTest1){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    Solution s;
    EXPECT_EQ(2, s.majorityElement(v));
}
TEST(ElementTest, NormalTest2){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    Solution s;
    EXPECT_EQ(2, s.majorityElement(v));
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
