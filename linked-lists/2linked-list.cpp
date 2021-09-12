// add two numbers:given two numbers in form of linked lists BUT in reverse order, output sum in linked list
// https://leetcode.com/explore/interview/card/amazon/77/linked-list/513/

// example: 
// number1: 2 -> 4 -> 3 (342)
// number2: 5 -> 6 -> 4 (465)
// output : 7 -> 0 -> 8 (708)

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

// class ListNode{
//     public:
//         int val;
//         ListNode* next;
// };

int main(){
    ListNode *l0 = new ListNode();
    ListNode *l1 = new ListNode();
    ListNode *l2 = new ListNode();

    ListNode *m0 = new ListNode();
    ListNode *m1 = new ListNode();
    ListNode *m2 = new ListNode();

    l0->val = 2;
    l0->next = l1;
    l1->val = 4;
    l1->next = l2;
    l2->val = 3;
    l2->next = NULL;

    m0->val = 5;
    m0->next = m1;
    m1->val = 6;
    m1->next = m2;
    m2->val = 4;
    m2->next = NULL;

    
// *********************************************** //

// FIXME: extra empty node added in the end

    ListNode *l = l0;
    ListNode *m = m0;
    ListNode *sol = new ListNode();
    ListNode *curr = sol;
    int x=0,y=0,carry=0,sum=0,count=0;

    while(l!=NULL || m!=NULL || carry){
        x = l?l->val:0;
        y = m?m->val:0;
        
        
        sum = x+y+carry;
        carry = (x+y)/10;
        // sol->val = sum % 10;
        cout << sol->val << "   ";
        
        l = l->next;
        m = m->next;
        sol->next = new ListNode(sum % 10);
        sol = sol->next;

        cout << x << " " << y << " " << carry << " " << sum << " " << endl;
    }

    curr = curr->next;
    while(curr != NULL){
        cout << curr->val << " ";
        curr = curr->next;
    }

    return 0;
}