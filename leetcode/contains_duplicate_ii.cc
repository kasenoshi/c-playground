#include <unordered_map>
#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i = 0; i < (int)nums.size(); i++){
            if(m.find(nums[i]) != m.end() && i - k <= m[nums[i]])
                return true;
            m[nums[i]] = i;
        }
        return false;
    }
};

TEST(DupTest, NormalInput){
    Solution s;
    vector<int> v;
    EXPECT_EQ(false, s.containsNearbyDuplicate(v, 2));
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(5);
    EXPECT_EQ(true, s.containsNearbyDuplicate(v, 2));
    v.clear();
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    EXPECT_EQ(false, s.containsNearbyDuplicate(v, 2));
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
