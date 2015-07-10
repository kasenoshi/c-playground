#include <vector>
#include <stdlib.h>
#include "gtest/gtest.h"

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution{
    public:
        ListNode *detectCycle(ListNode *head){
            ListNode *turtle = head;
            ListNode *hare = head;
            while(hare != NULL && turtle != NULL){
                hare = hare->next;
                turtle = turtle->next;
                if(hare != NULL)
                    hare = hare->next;
                if(hare == turtle)
                    break;
            }
            if(hare == NULL)
                return NULL;
            turtle = head;
            while(turtle != hare){
                turtle = turtle->next;
                hare = hare->next;
            }
            return hare;
        }
};
ListNode *createList(vector<int> list){
    if(list.empty())
        return NULL;
    vector<int>::iterator it = list.begin();
    ListNode *head = new ListNode(*it);
    it++;
    ListNode *p = head;
    for(; it != list.end(); it++){
        p->next = new ListNode(*it);
        p = p->next;
    }
    return head;
}

TEST(LinkedListTest, EmptyInput){
    Solution solution;
    EXPECT_EQ(NULL, solution.detectCycle(NULL));
}
TEST(LinkedListTest, NormalInputNoCycle){
    Solution solution;
    vector<int> data;
    for(int i = 0; i < 5; i++) data.push_back(i);
    ListNode *head = createList(data);
    EXPECT_EQ(NULL, solution.detectCycle(head));
}
TEST(LinkedListTest, NormalInputCycle){
    Solution solution;
    vector<int> data;
    for(int i = 0; i < 5; i++) data.push_back(i);

    ListNode *head = createList(data);
    ListNode *p = head;

    while(p->next != NULL)
        p = p->next;
    p->next = head->next->next;

    EXPECT_EQ(2, solution.detectCycle(head)->val);
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
