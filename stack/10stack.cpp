// min stack: Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
// https://leetcode.com/problems/min-stack/

// simple stack problem. use an additional supporting stack to store min value

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    stack<int> ss;

    MinStack() {    
    }
    
    void push(int val) {
        s.push(val);
        if(ss.size()==0 || ss.top()>=val){
            ss.push(val);
        }
    }
    
    void pop() {
        if(s.size()==0){
            return;
        }
        if(s.top()==ss.top()){
            ss.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
        
    }
    
    int getMin() {
        return ss.top();
        
    }
};

int main(){

    MinStack* minstk = new MinStack();
    minstk->push(7);
    minstk->push(10);
    minstk->push(3);
    minstk->push(1);
    minstk->push(32);
    minstk->pop();
    int x = minstk->getMin();
    cout << x << endl;
    minstk->pop();
    x = minstk->getMin();
    cout << x << endl;
    return 0;
}