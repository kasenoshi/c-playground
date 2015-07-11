#include <string>
#include "gtest/gtest.h"

using namespace std;

// compile with -std=c++11

class Solution {
public:
    string addBinary(string a, string b) {
        char c_a;
        char c_b;
        string c;
        char carry = 0;
        while(a.length() || b.length()){
            c_a = getBack(a);
            c_b = getBack(b);
            char temp = c_a + c_b + carry;
            carry = temp / 2;
            temp = temp % 2;
            if(temp)
                c = '1' + c;
            else
                c = '0' + c;
        }
        if(carry)
            c = '1' + c;
        return c;
    }
    char getBack(string &s){
        if(s.length() == 0)
            return 0;
        char c = s.back();
        s.pop_back();
        return c - '0';
    }
};

TEST(BinTest, EmptyInput){
    Solution s;
    string a;
    string b;
    EXPECT_EQ("", s.addBinary(a, b));
}
TEST(BinTest, SingleEmptyInput1){
    Solution s;
    string a;
    string b = "1";
    EXPECT_EQ("1", s.addBinary(a, b));
}
TEST(BinTest, SingleEmptyInput2){
    Solution s;
    string a = "1";
    string b;
    EXPECT_EQ("1", s.addBinary(a, b));
}
TEST(BinTest, SingleEmptyInput3){
    Solution s;
    string a = "0";
    string b;
    EXPECT_EQ("0", s.addBinary(a, b));
}
TEST(BinTest, NormalInput){
    Solution s;
    string a = "11";
    string b = "1";
    EXPECT_EQ("100", s.addBinary(a, b));
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
