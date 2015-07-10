#include "gtest/gtest.h"
#include <queue>

using namespace std;

class Stack {
public:
    queue<int> q;
    // Push element x onto stack.
    void push(int x) {
        queue<int> temp;
        temp.push(x);
        while(!q.empty()){
            temp.push(q.front());
            q.pop();
        }
        q = temp;
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop();
    }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};

TEST(StackTest, NormalTest){
    Stack s;
    EXPECT_EQ(true, s.empty());
    s.push(1);
    s.push(2);
    EXPECT_EQ(2, s.top());
    s.pop();
    EXPECT_EQ(1, s.top());
    s.pop();
    EXPECT_EQ(true, s.empty());
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
