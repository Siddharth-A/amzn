// sort a stack:

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void insert(stack<int> &s, int elem){
    if(s.size()==0 || s.top()<=elem){
        s.push(elem);
        return;
    }
    int prev_elem=s.top();
    s.pop();
    insert(s,elem);
    s.push(prev_elem);
}

void sort(stack<int> &s){
    if(s.size()==1){
        return;
    }
    int prev_elem=s.top();
    s.pop();
    sort(s);
    insert(s,prev_elem);
}


int main(){
    stack<int> s;
    s.push(8);
    s.push(2);
    s.push(3);
    s.push(7);
    s.push(6);
    s.push(4);
    s.push(5);

    sort(s);

    while(s.size()){
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}