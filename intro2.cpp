#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <ctime>
#include <thread>
#include <unistd.h>
#include <mutex>

using namespace std;


//BASICS##############################################################################################

/* INLINE FUNCTIONS: compiler places a copy of the function at every point in the code.
no control transfer takes place to function body. no overhead time. used for small func*/
inline int add (int a, int b){
    return(a+b);
}

/* DATA TYPES: for 32-bit systems: char:1,short int:2,int:4,long int:4,bool:1,float:4,double:8*/

/* SWITCH:*/
void switch_func()
{
    char input1='m';
    switch(input1){
        case 'm':
            cout << "monday" << endl;
            break;
        case 't':
            cout << "tuesday" << endl;
            break;
        default:
            cout << "invalid input" << endl;
    }
}

/* DO-WHILE LOOP: condition is checked after loop is executed once */
void dowhile_func(){
    char input2='x';
    do{
        cout << "printing from do-while loop" << "\n";
    }while(input2=='y');
}

/* POINTERS: pointer is a variable whos valuable is address of another variable. it allows
you to you to update mem from multiple locations */
void pointer_func(){
    int *iptr;
    int x=5;
    iptr=&x;
    cout << "addr of variable x: " << iptr <<endl;
    cout << "value of variable x: " << *iptr <<endl;
    cout << "addr of pointer: " << &iptr <<endl;
      
}

/* ARRAYS: eries of elements of same type referenced by using the index size needs
to be given before run time. static */
void array_func(){
    int array1[6]={1,2,3,4,5,6};
    for(int i:array1)
        cout << i << " ";
    cout << endl;
    
    int array2[5];
    array2[0]=7;

    //dynamic array
    double *array3ptr;
    int size=3;
    array3ptr = new double[size];
    for (int i=0; i<size;i++)
        array3ptr[i] = i;
    for (int i=0; i<size;i++)
        cout << array3ptr[i] << " ";
    cout << endl;
    delete[] array3ptr;

    int array4[] = { 10, 20, 30 };
}

/* VECTORS: Vectors are the same as dynamic arrays with the ability to resize itself 
automatically when an element is inserted or deleted */
void vector_func(){
    vector<int> v1;
    for(int i=0; i<4; i++)
        v1.push_back(i);
    for(int i=0;i<v1.size();i++)
       cout << v1[i] << " ";
    cout << endl;

    vector<int> v2 {40,50,60};
    for(int i=0;i<v2.size();i++)
       cout << v2[i] << " ";
    
    // The auto keyword is a simple way to declare a variable that has a complicated type. 
    // For example, you can use auto to declare a variable where the initialization expression 
    // involves templates, pointers to functions, or pointers to members
    for (auto x:v2)
        cout << x << " ";
}

/* FUNCTION OVERLOADING: two functions with same name have different parameters. plymorphism is C++.
examples: void print() void print(int a, double b) void print(double a, int b)
    - PASS BY VALUE: values changed inside func dont change actual params print(a,b)
    - PASS BY ADDRESS: values changed inside func change actual params print(a,b)
    - PASS BY POINTER: values changed inside func change actual params print(&a, &b)
*/
void overloading_val(int a,int b){
    a=10;
    b=10;
}
void overloading_addr(int &a,int &b){
    a=20;
    b=20;
}
void overloading_ptr(int *a,int *b){
    *a=30;
    *b=30;
}

void overloading_func(){
    int a=100;
    int b=100;
    overloading_val(a,b);
    cout << "a: " << a << endl;
    overloading_addr(a,b);
    cout << "a: " << a << endl;
    overloading_ptr(&a,&b);
    cout << "a: " << a << endl;
}

/*CLASS:
CONTRUCTORS/DECONTRSUCTORS:
    - called automatically, has same name as the class name
    - we only need destructor when we have dynamically allocated memory to avoid mem leak

FRIEND FUNCTIONS: function defined outside of class but has access to private and protected variables.

INHERITENCE:
    - inheritence allows us to define a class in terms of another class
    - the class from which new class inherits properties is called base class
    - the new class is derived class

ACCESS SPECIFIERS:
    - public: can be accessed by anybody
    - protected: can be accessed by Base members, friends, and derived classes
    - private: can only be accessed by Base members and friends (but not derived classes)

FUNCTION OVERLOADING: two functions with same name but different params
FUNCITON OVERRIDING: if derived class defines same function as base class

VIRTUAL FUNCTIONS & ABSTRACT CLASSES:
    - virtual function: function declared in base clase and overridden in derived class
    - pure virtual function: function for which we dont have an implementation in base class
    - abstract class: if a class has 1 virtual function, its known as abstract
    - abstract classes cannot be instantiated

MULTIPLE INHERITENCE:
    - when derived class derives from two base classes
    - we need to use scope resolution to avoid ambiguity errors

STATIC DATA MEMBERS:
    - can be accessed without initiating object of the class
    - need to be initialized outside of class
    - static keyword allows functions to be independent of the class/object
*/

class animal{
private:
    int population;
    int food;
    int color;

public:
    static int count;

    animal(){
        population=10;
        food=20;
        color=30;
    };
    animal(int a, int b, int c){
        population=a;
        food=b;
        color=c;
    }
    void print_info(){
        cout << "pop: " << population << endl;
        cout << "food: " << food << endl;
        cout << "color: " << color << endl;

    }
    void make_sound(){
        cout << "class:animal sound: generic" << endl;
    }
    friend void f_print_info(animal &x);
};

int animal::count=4;

void f_print_info(animal &x){
        cout << "pop: " << x.population << endl;
        cout << "food: " << x.food << endl;
        cout << "color: " << x.color << endl;
}

class mamal : public animal{
private:
    int legs;
    int hands;

public:
    mamal(){
        legs=2;
        hands=2;
    }
    mamal(int a, int b){
        legs=a;
        hands=b;
    }
    void pprint_info(){
        cout << "legs: " << legs << endl;
        cout << "hands: " << hands << endl;
    }

};

void class_func(){
    animal a1;
    animal a2(9,10,11);
    a1.print_info();
    cout << endl;
    f_print_info(a2);
    
    cout << "animal::count value: " << animal::count << endl;

    cout << endl;
    mamal m1;
    m1.make_sound();
    m1.print_info();
    m1.pprint_info();
    cout << endl;
    f_print_info(m1);
}

/* FUNCTION TEMPLATES: special functions that can operate with generic
   types. we pass data type as param
*/
template <typename T>
T template_func(T x, T y){
    cout << x+y << endl;
    return (x+y);
}

/* EXCEPTION HANDLERS: An exception is a problem that arises during the exec. 
A C++ exception is a response to an exceptional circumstance that arises.
Exceptions provide a way to transfer control in code. way to add info to SIG TRAPs

    - throw − throws an exception when a problem shows up
    - catch − catch an exception with an exception handler in code where you want to handle err
    - try − identify block of code for which particular exceptions will be activated. It's followed by catch block
*/
int divide(int a, int b){
    //divide by zero exception
    if(b==0)
        throw("division by zero!");
    return (a/b);
}
void exception_func(){
    try
    {
        int x = divide(20,0);
        cout << "divide result: " << x << endl;
    }
    // catch(const std::exception& e)
    catch(const char* msg)
    {
        // cerr << e.what() << endl;
        cerr << msg << endl;
    }  
}

//HEAP##############################################################################################
/*HEAP ALGORITHM USAGE
HEAP: is a special Tree-based data structure in which the tree is a complete binary tree
COMPLETE BINARY TREE: is a special type of binary tree where all the levels of the tree are 
filled completely except the lowest level nodes which are filled from as left as possible

QUEUE: is a FIFO dat structure.

TIME COMPLEXITY:
- top, push, pop: O(1)

PRIORITY QUEUE: is a C++ STL container built to replicate heap and use an array or vector 
as an internal structure. 

TIME COMPLEXITY:
- push, pop: O(log n)
- empty, size, top: O(1)

USE-CASE:
heap data structure should be used when K is given along with "min" "max" keywords
for e.x.: find the kth largest element in the array

max-heap: max value is sorted from top to bottom. hence, when asked 3rd smallest,
limit size of maxheap to 3 and sort throuh input. maxheap.top will be k smallest

min-heap: min value is sorted from top to bottom. hence, when asked 3rd largest,
limit size of minheap to 3 and sort throuh input. minheap.top will be k largest

*/
void kthlargestelement(){
    vector <int> input1 = {7,10,4,3,20,15};
    int k=3;
    priority_queue<int, vector<int>, greater<int>> minheap; //min-heap
    
    for(auto i:input1){
        minheap.push(i);
        if(minheap.size()>k)
            minheap.pop();
    }
    cout << k << "th largest element: " << minheap.top() << endl;
}

void kthsmallestelement(){
    vector<int> input2 = {7,10,4,3,20,15};
    int k=2;
    priority_queue<int> maxheap;
    for(auto i:input2){
        maxheap.push(i);
        if(maxheap.size()>k)
            maxheap.pop();
    }
    cout << k << "th smallest element: " << maxheap.top() << endl;
}

void knearlysortedarray(){
    vector<int> input3 = {6,5,3,2,8,10,9};
    int k=3;
    vector<int> sol;
    priority_queue<int, vector<int>, greater<int>> minheap;
    for(auto i:input3){
        minheap.push(i);
        if(minheap.size()>k){
            sol.push_back(minheap.top());
            minheap.pop();
        }
    }
    while(minheap.size()){
        sol.push_back(minheap.top());
        minheap.pop();
    }
    for (auto j:sol)
        cout << j << " ";
    cout << endl;
}

void kclosestnum(){
    vector<int> input4 = {1,6,3,9,12,7,13};
    int k=3, x=12;
    priority_queue<pair<int,int>> maxheap;
    for(auto i:input4){
        maxheap.push(make_pair(abs(x-i), i));
        if(maxheap.size()>k)
            maxheap.pop();
    }
    cout << k << " closest values to " << x << " : " << endl;
    while(maxheap.size()>0){
        cout << maxheap.top().second << endl;
        maxheap.pop();
    }
}

void kmostfrequent(){
#ifndef pp
#define pp pair<int,int>
    vector<int> input5 = {1,1,1,1,3,2,2,4,6,6,6};
    int k=2;
    unordered_map<int, int> mp;
    priority_queue<pp, vector<pp>, greater<pp>> minheap;

    for(auto x:input5){
        mp[x]++;
    }
    for(auto y:mp){
        minheap.push(make_pair(y.second, y.first));
        if(minheap.size()>k)
            minheap.pop();
    }
    cout << k << " most frequent elements: " << endl;
    while(minheap.size()>0){
        cout << "element: " << minheap.top().second << ", frequency: " << minheap.top().first << endl;
        minheap.pop();
    }
#endif
}

//STACK##############################################################################################
/*STACK ALGORITHM USAGE
STACK: is a LIFO data structure.

TIME COMPLEXITY:
- top, push, pop: O(1)

USE-CASE:
whenever the brute force solution seems like a double for loop, use stack
*/

void nextgreatestright(){
    // next greatest element (to the right)
    vector<int> input1={1,3,0,0,1,2,4};
    vector<int> sol;
    stack<int> s;

    for(int i=input1.size()-1;i>=0;i--){
        // stack empty
        if(s.size()==0)
            sol.push_back(-1);
        // s.top > input
        else if(s.top()>input1[i])
            sol.push_back(s.top());
        // s.top <= input
        else if(s.top()<=input1[i]){
            while(s.top()<=input1[i] && s.size()>0)
                s.pop();
            if(s.size()==0)
                sol.push_back(-1);
            else if(s.top()>input1[i])
                sol.push_back(s.top());
        }
        s.push(input1[i]);
    }
    reverse(sol.begin(),sol.end());
}

void nextsmallestright(){
    vector<int> input={1,3,0,0,1,2,4};
    stack<int> s;
    vector<int> sol;

    for(int i=input.size()-1;i>=0;i--){
        //s.size = 0
        if(s.size()==0)
            sol.push_back(-1);

        //s.top < input
        else if(s.top()<input[i])
            sol.push_back(s.top());

        // s.top > input
        else if(s.top()>=input[i]){
            while(s.size()>0 && s.top()>=input[i])
                s.pop();
            if(s.size()==0)
                sol.push_back(-1);
            else if(s.top()<input[i])
                sol.push_back(s.top());
        }
        s.push(input[i]);
    }
    reverse(sol.begin(),sol.end());

    for (auto x:sol)
        cout << x << " ";
}

/*MULTI-THREADING###################################################################################
CONCURRENCY/MULTI-THREADING: appearance of in-parallel execution achieved via multi-threading. e.x.: chatting
on teams with multiple people is you goig back and forth

PARALLELISM: code executing in parallel by leveraging multi-cores of the system. e.x.: singing in shower

DATA RACE: when at least two threads can simultaneously access a variable or memory location
*/
mutex m1;

void print1(int n){
    cout << "print integer: " << n << endl;
}

void print2(){
    // m1.lock();
    for(int i=0;i<=20;i++)
        cout << "print2:" << i << endl;
    // m1.unlock();
}

void multithreading1(){
    // thread t1(print1, 99);
    // t1.join();
    // thread t2(print1, 100);
    // t2.join();

    // vector<int> v = {23,33,43,53};
    // vector<thread> th;
    // for(int i=0;i<v.size();i++){
    //     th.push_back(thread(print1, v[i]));
    // }

    // for(auto &x:th)
    //     x.join();

    thread t3(print2);
    t3.join();
    for(int i=0;i<=20;i++)
        cout << "multithreading1:" << i << endl;
}

//LINKED-LISTS#######################################################################################
/*
LINKED-LIST: A linked list is a linear data structure, in which the elements are not stored at contiguous 
memory locations.

TIME COMPLEXITY:
- insertion/deletion: O(n)

USE-CASE:
- dynamic mem allocation: memory efficient
- ease of insertion/deletion
- random access of node not allowed. need to travese LL
- 
*/
class node{
public:
    int data;
    node* next;
};

void print_linklist(node** head){
    node* curr = *head;
    int i=0;
    while(curr!=NULL){
        cout << "node " << i << ": " << curr->data << "     ";
        curr = curr->next;
        i++; 
    }
    cout << endl;
}

void insert_helper(node** head, int x){
    node* curr = *head;
    while(curr->next != NULL){ //important condition. curr->next not curr
        curr = curr->next;
    }
    node* fourth=new node();
    fourth->data=x;
    fourth->next=NULL;
    curr->next=fourth;
}

void insertatk_helper(node** head, int pos, int x){
    node* curr = *head;
    node* newnode=new node();
    newnode->data=x;
    int counter=0;

    if(pos==0){
        newnode->next=*head;
        *head = newnode;
    }
    
    else if(pos!=0){
        while(curr->next!=NULL){
            curr=curr->next;
            counter++;
            if(counter==pos-1){ //important condition.
                newnode->next=curr->next;
                curr->next=newnode;
            }
        }
    }
}

void insert_linklist(){
    node* head=new node();
    node* second=new node();
    node* third=new node();

    head->data=33;
    head->next=second;
    second->data=44;
    second->next=third;
    third->data=55;
    third->next=NULL;

    insert_helper(&head, 77);
    insertatk_helper(&head, 0, 66);
    print_linklist(&head);
}

int main()
{
    // BASICS
    // cout << add(2,3) << endl;
    // switch_func();
    // dowhile_func();
    // array_func();
    // vector_func();
    // pointer_func();
    // overloading_func();
    // class_func();
    // template_func(5,5);
    // exception_func();

    // HEAP
    // kthlargestelement();
    // kthsmallestelement();
    // knearlysortedarray();
    // kclosestnum();
    // kmostfrequent();

    // STACK
    // nextgreatestright();
    // nextsmallestright();

    // MULTI-THREADING
    // multithreading1();

    // LINKED-LIST
    insert_linklist();


    return 0;
}