#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long x = (long)min(C, G) - max(A, E);
        long y = (long)min(D, H) - max(B, F);
        int inner = 0;
        if(x > 0 && y > 0)
            inner = x * y;
        int area_a = (C - A) * (D - B);
        int area_b = (G - E) * (H - F);
        return area_a + area_b - inner;
    }
};

TEST(AreaTest, NormalTest){
    Solution s;
    EXPECT_EQ(45, s.computeArea(-3, 0, 3, 4, 0, -1, 9, 2));
    EXPECT_EQ(8, s.computeArea(-3, -3, -1, -1, 2, 2, 4, 4));
    EXPECT_EQ(64, s.computeArea(0, 0, 2, 2, -4, -4, 4, 4));
    EXPECT_EQ(2, s.computeArea(-1500000001, 0, -1500000000, 1, 1500000000, 0, 1500000001, 1));
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
