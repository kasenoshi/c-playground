#include "gtest/gtest.h"

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution{
    public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
            return NULL;

        ListNode *p1 = head;
        ListNode *p2 = head;
        ListNode *prev = head;

        while(--n >= 0 && p2 != NULL){
            p2 = p2->next;
        }
        while(p2 != NULL){
            prev = p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        if(p1 != NULL && p1 != head){
            prev->next = p1->next;
            delete p1;
            return head;
        }
        else{
            head = p1->next;
            delete p1;
            return head;
        }
    }
};

TEST(ListTest, NormalInput){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    Solution s;
    EXPECT_EQ(3, head->next->next->val);
    head = s.removeNthFromEnd(head, 2);
    EXPECT_EQ(4, head->next->next->val);
}
TEST(ListTest, OneInput){
    ListNode *head = new ListNode(1);
    Solution s;
    EXPECT_EQ(1, head->val);
    EXPECT_EQ(NULL, head->next);
    head = s.removeNthFromEnd(head, 1);
    EXPECT_EQ(NULL, head);
}
TEST(ListTest, TwoInput){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    Solution s;
    EXPECT_EQ(1, head->val);
    head = s.removeNthFromEnd(head, 2);
    EXPECT_EQ(2, head->val);
}
int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
