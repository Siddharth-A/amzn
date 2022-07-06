// 1 https://leetcode.com/problems/next-greater-element-ii/
// 2 https://www.geeksforgeeks.org/previous-greater-element/
// 3 https://www.geeksforgeeks.org/find-the-nearest-smaller-numbers-on-left-side-in-an-array/
// 4 https://www.geeksforgeeks.org/next-smaller-element/
// 5 https://leetcode.com/problems/online-stock-span/
// 


#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;

void nextgreatestelement(vector<int> input){
    // start from end of vector
    stack<int> s;
    vector<int> sol;

    for(int i=input.size()-1;i>=0;i--){
        // case1: stack empty
        if(s.size()==0)
            sol.push_back(-1);
        
        // case2: stack top > input
        else if(s.size()>0 && s.top()>input[i])
            sol.push_back(s.top());
        
        // case3: stack top < input
        else if(s.top()<=input[i] && s.size()>0){
            while(s.top()<=input[i] && s.size()>0)
                s.pop();

            if(s.size()==0)
                sol.push_back(-1);

            else if(s.top()>input[i])
                sol.push_back(s.top());

        }
        s.push(input[i]);
    }
    reverse(sol.begin(),sol.end());
    for (auto x:sol)
        cout << x << " ";
    cout << endl;

}

void previousgreatestelement(vector<int> input){
    stack<int> s;
    vector<int> sol;

    for(int i=0;i<=input.size()-1;i++){
        if(s.size()==0)
            sol.push_back(-1);
        
        else if(s.top()>input[i])
            sol.push_back(s.top());
        
        else if(s.size()>0 && s.top()<=input[i]){
            while(s.size()>0 && s.top()<=input[i])
                s.pop();
            if(s.size()==0)
                sol.push_back(-1);
            else if(s.top()>input[i])
                sol.push_back(s.top());
        }
        s.push(input[i]);
    }
    for(auto i:sol)
        cout << i << " ";
    cout << endl;
    
}

void nextsmallestelement(vector<int> input){
    stack<int> s;
    vector<int> sol;

    for(int i=input.size()-1;i>=0;i--){

        s.push(input[i]);
    }
}

int main()
{
    vector<int> input1={1,3,0,0,1,2,4};
    // nextgreatestelement(input1);         //1 (NGR)(start from reverse array)
    // previousgreatestelement(input1);     //2 (NGL)
    nextsmallestelement(input1);    //4
    return 0;
}