// 1    print 1 to n numbers / print n to 1 numbers
// 5    https://leetcode.com/problems/maximum-depth-of-binary-tree/
// 7    sort stack using recursion
// 10   https://leetcode.com/problems/k-th-symbol-in-grammar/
// 12   print all substrings of a string
// 14   permutation with spaces
// 15   permutation with case change



/*!
* \brief -  
* time complexity:  
* space complexity: 

* recursion is used in arrays, strings, trees, graphs(DFS, flood fill)
* recursion algorithms: DP, BT, DNC
* how to approach recursion problems: 
*                                       1) IP/OP recrusive tree 
*                                       2) BIH
*                                       3)
*                                       4) choice diagram

* BIH - base condition, induction, hypothesis is used for trees and linked lists mostly
* step 1:- design hypothesis: print1ton(n) will print digits upto n, print1ton(n-1) ...
* step 2:- induction: implement the hypothesis for n
* step 3:- base condition: print1ton(n) will stop when n==1
*
*/


#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void printnto1(int input){
    if(input == 1){                  //base condition
        cout << input << endl;
        return;
    }

    cout << input << " ";       //induction:  printing n from hypothesis
    printnto1(input-1);         //hypothesis: assuming printnto1(n-1) will print (n-1)...1 just print n


}

void print1ton(int input){

    if(input == 1){
        cout << input << " ";
        return;
    }

    print1ton(input-1);
    cout << input << " ";
}

int factorial(int input){
    // base condition
    if(input == 1)
        return input;
    
    //induction: multiply input after call to function
    //hypothesis: assume fact(n-1) will give (n-1) factorial. just multiply n
    int sol = input * factorial(input-1);
    return sol;
}

int heightofbinarytree(Node *input){

    //base condition
    if(input == NULL)
        return 0;
    
    // hypothesis
    int lh = heightofbinarytree(input->left);
    cout << "left: " << lh << endl;
    int rh = heightofbinarytree(input->right);
    cout << "right: " << rh << endl;


    return (1+max(lh,rh));
}

void insert(stack<int> &s, int temp){
    // base condition
    if(s.size()==0 || temp >= s.top()){
        s.push(temp);
        return;
    }
    int x = s.top();        //induction
    s.pop();
    insert(s,temp);        //hypothesis
    s.push(x);
}

void sortstack(stack<int> &s){
    // base condition
    if(s.size() == 1){
        return;
    }
    // induction
    int temp = s.top();
    s.pop();
    // hypothesis
    sortstack(s);
    insert(s, temp);
}

int symbolgrammer(int n, int k){
/*
row1: 0
row2: 0 1
row3: 0 1 1 0
row4: 0 1 1 0 1 0 0 1  
*/

    //base condition
    if(n==1 & k==1)
        return 0;

    int mid=pow(2,n-1)/2;
    //hypothesis
    if(k<=mid)
        return (symbolgrammer(n-1,k));
    else
        return !(symbolgrammer(n-1,k-mid));

    //induction    
}

void printsubset(vector<char> input, vector<char> output){
    if(input.size()==0){
        for(auto x:output)
            cout << x << ' ';
        cout << endl;
        return;
    }

    vector<char> op1;
    vector<char> op2;

    op1 = output;
    op2 = output;
    op2.push_back(input[0]);
    input.erase(input.begin()+0);

    printsubset(input,op1);
    printsubset(input,op2);

    

}

void permutationwithspace(vector<char> input, vector<char> output){
    // base condition
    if(input.size()==0){
        if(output.back() != '_'){
            for(auto x:output)
                cout << x << "";
            cout << endl;
        }
        return;
    }
    
    output.push_back(input[0]);
    input.erase(input.begin()+0);

    permutationwithspace(input,output);
    output.push_back('_');
    permutationwithspace(input,output);
}

void permutationwithcase(vector<char> input, vector<char> output){
    //base condition
    if(input.size()==0){
        for(auto x:output)
            cout << x << "";
        cout << endl;
        return;
    }

    vector<char> op1 = output;
    vector<char> op2 = output;
    op1.push_back(input[0]);
    op2.push_back((char)toupper(input[0]));
    input.erase(input.begin()+0);
    permutationwithcase(input, op1);
    permutationwithcase(input, op2);
}

int main(){
    // int n = 10;
    // printnto1(10);                                       //basics
    // print1ton(10);                                       //basics
    // cout << "factorial: " << factorial(4) << endl;       //basics


    //height of tree
    /***************************************************
    Node *root = new Node(60);
    root->left = new Node(50);
    root->right = new Node(70);

    root->left->left = new Node(45);
    root->left->right = new Node(55);

    root->left->left->left = new Node(43);
    root->left->left->right = new Node(47);

    root->left->left->right->right = new Node(49);
    int h = heightofbinarytree(root);
    cout << "height of binary tree: " << h << endl;
    **************************************************/

   //sort a stack
   /***************************************************
   stack<int> s;
    s.push(43);
    s.push(3);
    s.push(54);
    s.push(34);
    s.push(2);

    sortstack(s);
    while(s.size()){
        cout << s.top() << " ";
        s.pop();
    }
    **************************************************/

   //kth symbol grammer
   /***************************************************
   int n=4;
   int k=3;
    cout << symbolgrammer(n,k) << endl;
    **************************************************/

   //print subset
   /***************************************************
   vector<char> input={'a','b','c'};
   vector<char> output;
   printsubset(input,output);
    **************************************************/

   //permutation with spaces
   /***************************************************
   vector<char> input={'a','b','c'};
   vector<char> output;
   permutationwithspace(input, output);
   **************************************************/

  //permutation with case change
  vector<char> input={'a','b'};
  vector<char> output;
  permutationwithcase(input,output);


    return 0;
}