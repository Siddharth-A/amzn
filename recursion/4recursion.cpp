// print n to 1 using recursion
// also create a factorial function

#include <iostream>

using namespace std;

void print(int x){
    // base cond
    if(x==1){
        cout << x << " ";
        return;
    }
    cout << x << " ";
    print(x-1);
}

int factorial(int y){
    int result;
    if(y==1){
        return y;
    }
    result=y*factorial(y-1);
    return result;
}


int main(){
    print(8);
    cout << endl;
    int t = factorial(6);
    cout << t << endl;
    return 0;
}