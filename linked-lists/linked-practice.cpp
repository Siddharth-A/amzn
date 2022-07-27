// 1 basics of linked list
// 2 https://leetcode.com/explore/interview/card/amazon/77/linked-list/513/
// 3 https://leetcode.com/problems/merge-two-sorted-lists/
// 4
// 5
// 6
// 7
// 8

/*!
* \brief - linked list is a linear data structure, in which the elements are not stored at contiguous memory locations.

C++ basics:

    passbyref(var2,var3);
    void passbyref(int &x, int &y){
        int z=x;
        x=y;
        y=z;
    }

    passbypointer(&var2,&var3);
    void passbypointer(int *x, int *y){
        int z=*x;
        *x=*y;
        *y=z;
    }
*/

#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void insertnode(Node** head, int position, int numdata){
    cout << endl << "insert after node:" << position << endl;
    // three cases: new head, in between, tail
    Node* curr = *head;
    int counter = 0;

    // head
    if (position == 0){
        curr->next = *head;
        curr->data = numdata;
    }

    // tail or in between
    else{
        while(counter < position){
            curr = curr->next;
            counter++;
        }
        Node* insertednode = new Node();
        insertednode->next = curr->next;
        curr->next = insertednode;
        insertednode->data = numdata;
        
    }
}

void deletenode(Node **head, int position){
    cout << endl << "delete node:" << position << endl;
    Node* curr = *head;
    Node* prev = NULL;
    int counter = 0;

    while(counter < position){
        prev = curr;
        curr = curr->next;
        counter++;
    }
    
    // tail
    if (curr->next == NULL){
        free(curr);
        prev->next=NULL;
    }

    else{
        prev->next = curr->next;
        free(curr);
    }

}

void iterate(Node** head){
    cout << endl << "iterate linked list" << endl;
    Node* curr = *head;
    int i=0;
    while(curr !=NULL){
        cout << "node " << i << ": " << curr->data << endl;
        curr = curr->next;
        i++;
    }

}

void basics(){
    // list creation
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;

    // list iteration
    iterate(&head);

    // add node to list
    int x = 66;
    insertnode(&head,2,x);
    x = 77;
    insertnode(&head,1,x);
    iterate(&head);

    // delete a node from the list
    deletenode(&head,3);
    iterate(&head);


}

int main(){
    // basics();                    // 1
    // addtwonumbers();             // 2

    return 0;
}