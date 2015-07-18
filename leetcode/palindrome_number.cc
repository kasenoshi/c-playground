#include "gtest/gtest.h"

class Solution {
public:
    bool isPalindrome(int x) {
        //negative integers can never be palindromes
        if(x < 0){
            return false;
        }
        int digits = 1;
        int num = x;
        int MSB = 1;
        while((num /= 10)  != 0){
            digits++;
            MSB *= 10;
        }
        int low = 0;
        int high = 0;
        while(digits > 1){
            low = x % 10; //get least siginificant number
            high = x / MSB; //get most siginificant number
            if(low != high)
                return false;
            x %= MSB;
            x /= 10;
            digits -= 2;
            MSB /= 100;
        }
        return true;
    }
};

TEST(NUMBER_TEST, FET){
    Solution s;
    EXPECT_EQ(false, s.isPalindrome(-1));
    EXPECT_EQ(true, s.isPalindrome(0));
}
TEST(NUMBER_TEST, FEST_TRUE){
    Solution s;
    EXPECT_EQ(true, s.isPalindrome(1));
    EXPECT_EQ(true, s.isPalindrome(121));
    EXPECT_EQ(true, s.isPalindrome(12321));
    EXPECT_EQ(true, s.isPalindrome(1234321));
}
TEST(NUMBER_TEST, FEST_FALSE){
    Solution s;
    EXPECT_EQ(false, s.isPalindrome(12));
    EXPECT_EQ(false, s.isPalindrome(123));
    EXPECT_EQ(false, s.isPalindrome(1234));
    EXPECT_EQ(false, s.isPalindrome(12345));
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
