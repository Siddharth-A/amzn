// delete middle element of stack: https://www.geeksforgeeks.org/delete-middle-element-stack/

#include <iostream>
#include <stack>

using namespace std;

void delete_mid(stack<int> &s,int mid_point){
    if(mid_point==s.size()-1){
        s.pop();
        return;
    }
    int top_elem=s.top();
    s.pop();
    delete_mid(s,mid_point);
    s.push(top_elem);
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

    int mid_point=s.size()/2;

    delete_mid(s,mid_point);

    while(s.size()){
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}