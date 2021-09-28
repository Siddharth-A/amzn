// print 1 to n numbers:

#include <iostream>

using namespace std;

void print(int x){
    // base condition
    if(x==1){
        cout << "1" << endl;
        return;
    }
    // induction
    print(x-1);
    
    cout << x << endl;
        
}

int main(){
    int n=7;
    print(n);
    return 0;
}