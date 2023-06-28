#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

int main()
{
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
    return 0;
}