// reverse nodes in K-group:
// https://leetcode.com/explore/interview/card/amazon/77/linked-list/2977/

// 1 2 3 4 5 k=3
// 3 1 2 4 5

// 1 2 3 4 5 k=4
// 4 1 2 3 5

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

    int k = 3;
// ************************************ //
    ListNode* curr = l0;
    ListNode* prev = NULL;

    while(curr != NULL){
        if(l0->val == k){
            break;
        }
        else if(curr->val == k){
            prev->next = curr->next;
            curr->next = l0;
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    if(curr == NULL){
        cout << "k not found" << endl;
        return 0;
    }

    while(curr!=NULL){
        cout << curr->val << " ";
        curr=curr->next;
    }

    return 0;
}