#include "gtest/gtest.h"

class Solution{
    public:
        bool isPowerOfTwo(int n){
            if(n <= 0)
                return false;
            return ((n&(n-1)) == 0);
        }
};

TEST(PowerTest, Test){
    Solution s;
    EXPECT_EQ(false, s.isPowerOfTwo(0));
    EXPECT_EQ(true, s.isPowerOfTwo(1));
    EXPECT_EQ(true, s.isPowerOfTwo(2));
    EXPECT_EQ(true, s.isPowerOfTwo(65536));
    EXPECT_EQ(false, s.isPowerOfTwo(-1));
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
