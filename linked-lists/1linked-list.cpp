// introduction to linked lists:

#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
};


void deletenode(Node **headref, int position){
    Node *curr = *headref;
    Node *prev = NULL;
    int p=0;

    // if deleting head
    if (position == 0){
        *headref = curr->next;
        free(curr);
        return;
    }

    while(curr != NULL){
        if(p == position){
            prev->next = curr->next;
            free(curr);
            return;
        }
        else{
            prev = curr;
            curr = curr->next;
        }
        p++;
    }
    
    // // store pointer to node before node to be deleted
    // for(int i=0;i<position-1;i++){
    //     curr = curr->next;
    // }

    // Node* curr2 = curr->next->next;
    // free(curr->next);
    // curr->next = curr2;
}

int main(){
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

// inserting node in linked list

// 1) front of list
    Node* fourth = new Node();
    fourth->next = head;
    head = fourth;
    fourth->data = 0;
// 2) after specific node
    if (second == NULL){
        cout << "cannot be null" << endl;
    }
    Node* fifth = new Node();
    fifth->data = 99;
    fifth->next = second->next;
    second->next = fifth;
// 3)end of list


// traversing a linked list
    Node* curr = head;
    while(curr!=NULL){
        cout << curr->data << " "; 
        curr = curr->next;
    }
    cout << endl;

// deleting node in linked list at a given position
    int position = 3;
    deletenode(&head,position);

    Node* currr = head;
    while(currr!=NULL){
        cout << currr->data << " "; 
        currr = currr->next;
    }
    cout << endl;

    return 0;
}