// reverse stack via recursion: https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/

#include <iostream>
#include <stack>

using namespace std;

void insert(stack<int> &s, int prev){
    if(s.size()==0){
        s.push(prev);
        return;
    }
    int prev2=s.top();
    s.pop();
    insert(s,prev);
    s.push(prev2);
}

void reverse(stack<int> &s){
    if(s.size()==1){
        return;
    }
    int prev=s.top();
    s.pop();
    int curr=s.top();
    reverse(s);
    insert(s,prev);
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);

    
    stack<int> s1=s;
    while(s1.size()){
        cout << s1.top() << endl;
        s1.pop();
    }
    cout << "-------" << endl;

    reverse(s);

    while(s.size()){
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}
