#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

class LinkedList{
    public:
        ListNode *head;
        LinkedList(){
            ListNode *p;
            head = NULL;
            while(true){
                int input = -1;
                cout << "input your value(-1 to terminate):";
                cin >> input;
                if(input == -1)
                    break;
                if(head == NULL){
                    head = new ListNode(input);
                    p = head;
                }
                else{
                    p->next = new ListNode(input);
                    p = p->next;
                }
            }
        }
        void printList(){
            ListNode *p = head;
            while(p != NULL){
                cout << p->val << "->";
                p = p->next;
            }
            cout << endl;
        }
        int length(){
            ListNode *p = head;
            int length = 0;
            while(p != NULL){
                length++;
                p = p->next;
            }
            return length;
        }
        void deleteNode(int x){
            if(x == 0){
                ListNode *temp = head;
                head = head->next;
                delete(temp);
            }
            else if(x < length()){
                ListNode *prev = head;
                while(--x){
                    prev = prev->next;
                }
                ListNode *temp = prev->next;
                prev->next = temp->next;
                delete(temp);
            }
        }
        void insertNode(int x){
            if(x == 0){
                ListNode *temp = head;
                head = head->next;
                delete(temp);
            }
            else if(x < length()){
                ListNode *prev = head;
                while(--x){
                    prev = prev->next;
                }
                ListNode *temp = prev->next;
                prev->next = temp->next;
                delete(temp);
            }
        }
};

int main(){
    int x;
    LinkedList l;
    l.printList();
    cout << "length = " << l.length() << endl;
    cout << "delete index = ";
    cin >>x;

    l.deleteNode(x);
    l.printList();
    return 0;
}
