// merge two sorted linked lists: Merge two sorted linked lists and return it as a sorted list.
// https://leetcode.com/explore/interview/card/amazon/77/linked-list/2976/

// 1 2 4 
// 1 3 4
// 1 1 2 3 4 4

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

    ListNode *m0 = new ListNode();
    ListNode *m1 = new ListNode();
    ListNode *m2 = new ListNode();
    ListNode *m3 = new ListNode();
    ListNode *m4 = new ListNode();

    l0->val = 1;
    l0->next = l1;
    l1->val = 2;
    l1->next = l2;
    l2->val = 4;
    l2->next = NULL;

    m0->val = 1;
    m0->next = m1;
    m1->val = 3;
    m1->next = m2;
    m2->val = 4;
    m2->next = m3;
    m3->val = 5;
    m3->next = m4;
    m4->val = 8;
    m4->next = NULL;
// *********************************************** //

    ListNode* temp = new ListNode();
    ListNode* sol = temp;
    ListNode* l = l0;
    ListNode* m = m0;

    while(l!=NULL && m!=NULL){
        if(l->val <= m->val){
            temp->next = new ListNode(l->val);
            l = l->next;
        }
        else if(l->val > m->val){
            temp->next = new ListNode(m->val);
            m = m->next;
        }
        temp = temp->next;


    }
    
    while(m != NULL){
        temp->next = new ListNode(m->val);
        m = m->next;
        temp = temp->next;

    }

    while(l != NULL){
        temp->next = new ListNode(l->val);
        l = l->next;
        temp = temp->next;
    }

    sol = sol->next;
    while(sol != NULL){
        cout << sol->val << " ";
        sol = sol->next;
    }

    return 0;
}


