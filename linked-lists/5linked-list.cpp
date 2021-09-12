// reverse a linked list: given head of linked list, reverse it
// https://leetcode.com/explore/interview/card/amazon/77/linked-list/2979/

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

int main(){
    ListNode *l0 = new ListNode();
    ListNode *l1 = new ListNode();
    ListNode *l2 = new ListNode();
    ListNode *l3 = new ListNode();
    ListNode *l4 = new ListNode();

    l0->val = 1;
    l0->next = l1; 
    l1->val = 2;
    l1->next = l2;
    l2->val = 3;
    l2->next = l3;
    l3->val = 4;
    l3->next = l4;
    l4->val = 5;
    l4->next = NULL;
// ************************************ //
    ListNode* next = l0;
    ListNode* curr = l0;
    ListNode* prev = NULL;

    while(next != NULL){
        next = next->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        // cout << next->val << endl;
    }

    while(prev!=NULL){
        cout << prev->val << " ";
        prev = prev->next;
    }

    return 0;
}