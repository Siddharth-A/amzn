// 1 print 1 to n numbers / print n to 1 numbers

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

using namespace std;

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

int main(){
    int n = 10;
    // printnto1(10);
    // print1ton(10);
    // cout << "factorial: " << factorial(4) << endl;

    return 0;
}