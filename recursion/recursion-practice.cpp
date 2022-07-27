// print 1 to n numbers

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

void print1ton(int input){
    if(input == 1)                  //base condition
        cout << input << endl;

    else if(input > 1){
        cout << input << " ";       //induction
        print1ton(input-1);         //hypothesis
    }

}

int main(){
    int n = 10;
    print1ton(10);
    return 0;
}