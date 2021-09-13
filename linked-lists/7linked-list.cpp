// merge K sorted lists:You are given an array of k linked-lists lists, each linked-list is sorted in ascending order. Merge all the linked-lists into one sorted linked-list and return it.
// https://leetcode.com/problems/merge-k-sorted-lists/

// 1 2 4 
// 1 3 4 5 8
// 2 6

#include <iostream>
#include <vector>
#include <queue>

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

    ListNode *n0 = new ListNode();
    ListNode *n1 = new ListNode();

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

    n0->val = 2;
    n0->next = n1;
    n1->val = 6;
    n1->next = NULL; 

    vector<ListNode*> lists;
// *********************************************** //
    priority_queue<int,vector<int>,greater<int>> minheap;
    for (int i=0;i<lists.size();i++){
        ListNode* it = lists[i];
        while(it!=NULL){
            minheap.push(it->val);
            it = it->next;
        }
    }
    
    ListNode *temp = new ListNode();
    ListNode *sol = temp;
    
    while(minheap.size() > 0){
        temp->next = new ListNode(minheap.top());
        minheap.pop();
        temp = temp->next;
    }
    
    sol = sol->next;

    while(sol != NULL){
        cout << sol->val << " ";
        sol = sol->next;
    }

    return 0;
}


