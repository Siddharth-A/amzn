#include <iostream>
#include <string>

using namespace std;

/*
FUNCTIONS:
- inline function: compiler places a copy of the function at every point in the code.
no control transfer takes place to function body. no overhead time. used for small func
*/

inline int add(int a, int b){
    return (a+b);
}

// STRUCTURES:

// CLASSES:

// PASSING CLASS OBJECTS INTO FUNCTIONS:

// FRIEND FUNCTIONS:

// INHERITENCE:

// VIRTUAL FUNCTIONS & ABSTRACT CLASSES:
// makesound is a virtual function. we only need 1 get function
// in which we can pass pointer to get sound from all classes

// PURE VIRTUAL FUNCTIONS:
// classes with pure virutal function cannot be initiated.

// MULTIPLE INHERITENCE:

// STATIC DATA MEMBERS:
// used to make functions/variables independent of the class/object
// static functions can only access other static functions

// FUNCTION TEMPLATES:


int main(){
    /*
    DATA TYPES:
    - derived datatypes: arrays,functions,pointers,references
    - built in datatypes: int,char,float,double,void
    - user defined datatypes: structures,unions,classes,enumeration
    for 32-bit systems: char:1,short int:2,int:4,long int:4,bool:1,float:4,double:8
    */

    /*
    OPERATOR TYPES:
    - arithmetic: + - * / %
    - relational: == != > < >= <=
    - logical: && || !
    - assignment: a+=b a-=b a*=b (a=a+b)
    - bitwise: & | ^(xor) << >>
    - misc: sizeof condition? x:y (if condition true, x is returned)
    */

    /*
    SWITCH:
    */
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

    /*
    DO-WHILE LOOP:
    - condition is checked after loop is executed once
    */
    char input2='x';
    do{
        cout << "printing from do-while loop" << "\n";
    }while(input2=='y');

    /*
    ARRAYS:
    series of elements of same type referenced by using the index size needs
    to be given before run time. static
    */
    int array1[3]={1,2,3};
    int array2[5];
    array2[0]=7;

    /*
    POINTERS:
    pointer is a variable whos valuable is address of another variable. it allows
    you to you to update mem from multiple locations
    */
    int *iptr;
    double *dptr;
    char *cptr;
    float *fptr;

    int var1=5;
    iptr=&var1;
    // - *iptr gives value of var1
    // - iptr gives address of var1
    // - &iptr gives address of iptr
    // - pointer needs to point to address

    /*
    DYNAMIC MEMORY ALLOCATION:
    */
    int size, *arrayptr;
    cout << "enter size of array:" << endl;
    cin >> size;
    arrayptr = new int[size];
    cout << "enter values for array:" << endl;
    for(int i=0;i<size;i++){
        cin>>arrayptr[i];
    }

    /*
    FUNCTION OVERLOADING:
    two functions with same name have different parameters. plymorphism is C++.
    examples:
    void print() void print(int a, double b) void print(double a, int b)
    */

    /*
    - PASS BY VALUE:
    - PASS BY ADDRESS:
    - PASS BY POINTER:
    */
    // PASS BY VALUE: copies actual value of arg into func param
    // values changed inside func dont change actual params
    void passbyvalue(int x, int y){
        int z=x;
        x=y;
        y=z;
    }

    // PASS BY REFERENCE/PASS BY ADDRESS: copies reference of arg into func param
    // values changed inside func change actual params
    // passbyref(a,b)
    void passbyref(int &x, int &y){
        int z=x;
        x=y;
        y=z;
    }

    // PASS BY POINTER: copies address of arg into func param
    // values changed inside func change actual params
    // passbypointer(&x, &y)
    void passbypointer(int *x, int *y){
        int z=*x;
        *x=*y;
        *y=z;
    }
    int var2=5,var3=6;
    passbyvalue(var2, var3);
    passbyref(var2,var3);
    passbypointer(&var2,&var3);
    cout << var2 << endl;
    cout << var3 << endl;

    /*
    STRUCTURES:
    user defined data types which allow you to combine data types of diff types.
    */
    struct person{
        char name[100];
        int age;
        double salary;
    };

    person p1;
    cout << "name:" << endl;
    cin>>p1.name;
    cout << "age:" << endl;
    cin>>p1.age;
    cout << "salary:" << endl;
    cin>>p1.salary;
    cout << "name:" << p1.name << " age:" << p1.age << " salary:" << p1.salary << endl;

    person *ptr;
    ptr = &p1;
    cout << "Using pointer:- " << "name:" << ptr->name << " age:" << ptr->age << " salary:" << ptr ->salary << endl;

    /*
    ARRAY OF STRUCTURES:
    */
    person p2[2];
    cout << "input name age and salary for ";
    for(int i=0;i<2;i++){
        cout << "person" << i << ": ";
        cin>>p2[i].name;
        cin>>p2[i].age;
        cin>>p2[i].salary;
    }

    /*
    OBJECT ORINTED PROGRAMMING:
    */

    /*
    CLASS:
    */
    class cars{
        private:
        string company;
        string model;
        int price;

        public:
        cars(){
            cout << "default constructor called" << endl;
            company="default company";
            model="default model";
            price=0;
        }
        cars(string c, string m){
            cout << "parameterized constructor called" << endl;
            company=c;
            model=m;
        }
        void setdata(string c, string m, int p){
            company=c;
            model=m;
            price=p;
        }
        void displaydata(){
            cout << "company: " << company << endl;
            cout << "model: " << model << endl;
            cout << "price: " << price << endl;
        }
    };

    /*
    CONTRUCTORS/DECONTRSUCTORS:
    - called automatically, has same name as the class name
    - types:
    - default constructors: default basic type
    - parameterized constructors: has params passed into it
    - copy constructors: uses another object of same class to init
    - we only need destructor when we have dynamically allocated memory to avoid
    - mem leak
    */

    cars car1;
    car1.setdata("tesla","modelx", 80000);
    car1.displaydata();
    cars car2("tesla","models");
    car2.displaydata();

    /*
    PASSING CLASS OBJECTS INTO FUNCTIONS:
    */
    class complexnum{
        private:
        int real;
        float complex;

        public:
        complexnum(){
        }
        complexnum(int r, float c){
            real=r;
            complex=c;
        }
        int getreal(){
            return real;
        }
        float getcomplex(){
            return complex;
        }
        void displaydata(){
            cout << "real: " << real << endl;
            cout << "imaginary: " << complex << endl;
        }
        friend void addtoreal(complexnum &x);
    };
    complexnum add(complexnum a, complexnum b){
        int real;
        float complex;
        real=a.getreal()+b.getreal();
        complex=a.getcomplex()+b.getcomplex();
        complexnum c(real,complex);
        return c;
    }

    complexnum c1(1,1),c2(2,4),c3,*ptr2;
    c3 = add(c1,c2);
    c3.displaydata();
    //using pointer to point to object
    ptr2=&c3;
    ptr2->displaydata();

    /*
    FRIEND FUNCTIONS: function defined outside of class but has access to private
    and protected variables.
    */
    void addtoreal(complexnum &x){
        x.real=x.real+1;
    }
    addtoreal(c1);

    /*
    INHERITENCE:
    - inheritence allows us to define a class in terms of another class
    - the class from which new class inherits properties is called base class
    - the new class is derived class
    types of inheritence:
    - single level: 1 base class, 1 derived class from it
    - multi level: 1 base class, derived1 from base, derived2 to from derived1
    - multiple inheritence: 2 base class, deerived1 from base
    - hierarchical: 1 base class, derived1, derived2, derived3 from base
    */
    class shape{
        protected:
        int width;
        int height;
        public:
        shape(){
        }
        shape(int w, int h){
            width=w;
            height=h;
        }
        int getarea(){
            cout << "shape not specified" << endl;
            return 0;
        }
    };
    class rectangle: public shape{
        public:
        rectangle(int w, int h){
            width=w;
            height=h;
        }
        int getarea(){
            return (height*width);
        }
    };
    class triangle: public shape{
        public:
        triangle(int w, int h){
            width=w;
            height=h;
        }
    };

    rectangle r1(2,3);
    int a1 = r1.getarea();
    cout << "area: " << a1 << endl;
    triangle t1(2,3);
    int a2 = t1.getarea();
    cout << "area: " << a2 << endl;

    /*
    FUNCTION OVERLOADING: two functions with same name but different params
    FUNCITON OVERRIDING: if derived class defines same function as base class
    */

    /*
    VIRTUAL FUNCTIONS & ABSTRACT CLASSES:
    - virtual function: function declared in base clase and overridden in derived class
    - pure virtual function: function for which we dont have an implementation
    - abstract class: if a class has 1 virtual function, its known as abstract
    - abstract classes cannot be instantiated
    */
    class animal{
        public:
        virtual void makesound(){
            cout << "generic sound" << endl;
        }
        void eat(){
            cout << "eat generic food" << endl;
        }
    };
    class dog: public animal{
        public:
        void makesound(){
            cout << "dog sound" << endl;
        }
        void eat(){
            cout << "eat dog food" << endl;
        }
    };
    class cat: public animal{
        public:
        void makesound(){
            cout << "cat sound" << endl;
        }
        void eat(){
            cout << "eat cat food" << endl;
        }
    };
    void getsound(animal *ptr){
        ptr->makesound();
    }

    animal a1,*animalptr1,*animalptr2;
    dog d1,d2;
    cat c1,c2;
    a1.makesound();//generic
    a1.eat();//generic
    d1.makesound();//dog
    d1.eat();//dog
    c1.makesound();//cat
    c1.eat();//cat
    animalptr1=&d2;
    animalptr1->makesound();//dog
    animalptr1->eat();//generic
    animalptr2=&c2;
    animalptr2->makesound();//cat
    animalptr2->eat();//generic
    getsound(animalptr1);
    getsound(animalptr2);

   /*
   PURE VIRTUAL FUNCTIONS:
   */
    class bike{
        public:
        virtual void brand()=0;
        void color(){
            cout << "generic color" << endl;
        }
    };
    class mountainbike: public bike{
        public:
        void brand(){
            cout << "mountainbike brand" << endl;
        }
    };

    mountainbike m1;
    m1.brand();
    m1.color();

    /*
    MULTIPLE INHERITENCE:
    - when derived class derives from two base classes
    - we need to use scope resolution to avoid ambiguity errors
    */
    class A{
        public:
        void print(){
            cout << "class A print func" << endl;
        }
    };
    class B{
        public:
        void print(){
            cout << "class B print func" << endl;
        }
    };
    class C: public A, public B{
        public:
        void print(){
            A::print();
        }
    };

    C obj1;
    obj1.print();

    /*
    STATIC DATA MEMBERS:
    - can be accessed without initiating object of the class
    - need to be initialized outside of class
    - static keyword allows functions to be independent of the class/object
    */
    class myclass{
        public:
        int x;
        static int count;
        static int getcount(){
            return count;
        }
        myclass(){
            count++;
        }
    };
    int myclass::count=0;

    cout << myclass::count << endl;
    myclass obj2;
    obj2.x=4;
    obj2.count;
    cout << obj2.x << endl;
    cout << obj2.count << endl;

   /*
   FUNCTION TEMPLATES: special functions that can operate with generic
   types. we pass data type as param
   */
    template <typename T>
    T add(T x, T y){
        return (x+y);
    }

    add<int>(3,4);
    add<float>(2.3f,4.5f);//add f to explictely tell it is float (not dbl)


    return 0;
}

