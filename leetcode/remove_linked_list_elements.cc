#include "gtest/gtest.h"

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *p = head;
        ListNode *prev = head;
        while(p != NULL){
            if(p->val == val){
                if(p == head){
                    head = p->next;
                    delete p;
                    p = head;
                }
                else{
                    prev->next = p->next;
                    delete p;
                    p = prev->next;
                }
            }
            else{
                prev = p;
                p = p->next;
            }
        }
        return head;
    }
};

TEST(RemoveTest, EmptyInput){
    Solution s;
    EXPECT_EQ(NULL, s.removeElements(NULL, 0));
}
TEST(RemoveTest, OneInput){
    ListNode *head = new ListNode(1);
    Solution s;
    EXPECT_EQ(NULL, s.removeElements(head, 1));
}
TEST(RemoveTest, NormalInput1){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    Solution s;
    EXPECT_EQ(NULL, s.removeElements(head, 1));
}
TEST(RemoveTest, NormalInput2){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    Solution s;
    EXPECT_EQ(2, s.removeElements(head, 1)->val);
}
TEST(RemoveTest, NormalInput3){
    ListNode *head = new ListNode(2);
    head->next = new ListNode(1);
    Solution s;
    EXPECT_EQ(2, s.removeElements(head, 1)->val);
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
