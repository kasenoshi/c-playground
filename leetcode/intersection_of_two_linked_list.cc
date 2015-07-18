#include "gtest/gtest.h"


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = 0;
        int lengthB = 0;
        int diff = 0;
        ListNode *pA = headA, *pB = headB;
        while(pA != NULL && pB != NULL){
            pA = pA->next;
            pB = pB->next;
            lengthA++;
        }
        lengthB = lengthA;
        if(pA != NULL){
            while(pA != NULL){
                pA = pA->next;
                lengthA++;
            }
            diff = lengthA - lengthB;
        }
        if(pB != NULL){
            while(pB != NULL){
                pB = pB->next;
                lengthB++;
            }
            diff = lengthB - lengthA;
        }
        pA = headA;
        pB = headB;
        if(lengthA >= lengthB){
            while(--diff >= 0)
                pA = pA->next;
            while(pA != pB){
                pA = pA->next;
                pB = pB->next;
            }
        }
        if(lengthB > lengthA){
            while(--diff >= 0)
                pB = pB->next;
            while(pA != pB){
                pA = pA->next;
                pB = pB->next;
            }
        }
        return pA;
    }
};

TEST(LIST_TEST, FET_TEST1){
    Solution s;
    ListNode *headA = NULL;
    ListNode *headB = NULL;
    EXPECT_EQ(NULL, s.getIntersectionNode(headA, headB));
}
TEST(LIST_TEST, FET_TEST2){
    Solution s;
    ListNode *headA = new ListNode(1);
    ListNode *headB = NULL;
    EXPECT_EQ(NULL, s.getIntersectionNode(headA, headB));
}
TEST(LIST_TEST, FET_TEST3){
    Solution s;
    ListNode *headA = NULL;
    ListNode *headB = new ListNode(1);
    EXPECT_EQ(NULL, s.getIntersectionNode(headA, headB));
}
TEST(LIST_TEST, FEST_TEST1){
    Solution s;
    ListNode *headA = new ListNode(1);
    ListNode *headB = new ListNode(1);
    headA->next = new ListNode(2);
    headB->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headB->next->next = headA->next->next;
    headA->next->next->next = new ListNode(4);
    EXPECT_EQ(3, s.getIntersectionNode(headA, headB)->val);
}
TEST(LIST_TEST, FEST_TEST2){
    Solution s;
    ListNode *headA = new ListNode(1);
    ListNode *headB = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headB->next = headA->next->next;
    headA->next->next->next = new ListNode(4);
    EXPECT_EQ(3, s.getIntersectionNode(headA, headB)->val);
}
TEST(LIST_TEST, FEST_TEST3){
    Solution s;
    ListNode *headA = new ListNode(1);
    ListNode *headB = new ListNode(1);
    headA->next = new ListNode(2);
    headB->next = new ListNode(2);
    headB->next->next = new ListNode(3);
    headA->next->next = headB->next->next;
    headB->next->next->next = new ListNode(4);
    EXPECT_EQ(3, s.getIntersectionNode(headA, headB)->val);
}
TEST(LIST_TEST, FEST_TEST4){
    Solution s;
    ListNode *headA = new ListNode(1);
    ListNode *headB = new ListNode(1);
    headB->next = new ListNode(2);
    headB->next->next = new ListNode(3);
    headA->next = headB->next->next;
    headB->next->next->next = new ListNode(4);
    EXPECT_EQ(3, s.getIntersectionNode(headA, headB)->val);
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
