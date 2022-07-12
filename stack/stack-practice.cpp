// 1 https://leetcode.com/problems/next-greater-element-ii/
// 2 https://www.geeksforgeeks.org/previous-greater-element/
// 3 https://www.geeksforgeeks.org/find-the-nearest-smaller-numbers-on-left-side-in-an-array/
// 4 https://www.geeksforgeeks.org/next-smaller-element/
// 5 https://leetcode.com/problems/online-stock-span/
// 6 https://leetcode.com/problems/largest-rectangle-in-histogram/
// 7

// NGR: nearest greatest right (reverse)
// NGL: nearest greatest left
// stack questions time complexity: O(n) (NOTE: stack time complexity by itself is O(1))

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

void previoussmallestelement(vector<int> input){
    stack<int> s;
    vector<int> sol;

    for(int i=0;i<=input.size()-1;i++){
        // case 1:stack empty
        if(s.size()==0)
            sol.push_back(-1);

        // case 2:stack top < input[i]
        else if(s.size()>0 && s.top()<input[i])
            sol.push_back(s.top());

        // case 3: stack top > input[i]
        else if(s.size()>0 && s.top()>input[i]){
            while(s.size()>0 && s.top()>input[i])
                s.pop();
            if(s.size()==0)
                sol.push_back(-1);
            else if(s.top()<input[i])
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
        // case 1: stack empty
        if(s.size() == 0)
            sol.push_back(-1);

        // case 2: stack top < input
        else if(s.top() < input[i] && s.size()>0)
            sol.push_back(s.top());

        // case 3: stack top > input
        else if(s.size()>0 && s.top()>=input[i]){
            while(s.size()>0 && s.top()>=input[i])
                s.pop();

            if(s.size()==0)
                sol.push_back(-1);

            else if(s.top()<input[i])
                sol.push_back(s.top());

        }
        s.push(input[i]);
    }
    reverse(sol.begin(),sol.end());
    for (auto x:sol)
        cout << x << " ";
    cout << endl;
}

void stockspanproblem(vector<int> input){
    // find # of days stock was lower prior
    // above => next greater left (NGL)
    // look at index of vector
    stack<pair<int,int>> s;
    vector<int> sol;

    for(int i=0; i<=input.size()-1;i++){
        // case1: stack is empty
        if (s.size()==0)
            sol.push_back(-1);

        // case2: stack.top() > input[i]
        else if(s.size()>0 && s.top().first > input[i])
            sol.push_back(s.top().second);

        // case3: stack.top() <= input[i]
        else if(s.size()>0 && s.top().first <= input[i]){
            while(s.size()>0 && s.top().first <= input[i])
                s.pop();
            if(s.size()==0)
                sol.push_back(-1);
            else if(s.top().first > input[i])
                sol.push_back(s.top().second);
        }

        s.push(make_pair(input[i],i));
    }
    for(int j=0;j<=sol.size()-1;j++)
        cout << j - sol[j] << " ";
    cout << endl;

}

int maximumareahistogram(vector<int> input){
    // create NSL and NSR vectors
    // points where the current bar discontinues = width = (NSR-NSL-1)
    // area = width*input[i]
    vector<int> sol;
    vector<int> left;
    vector<int> right;
    vector<int> area;
    stack<pair<int,int>> s;
    stack<pair<int,int>> r;
    int max=0;

    // part1: NSL
    for(int i=0;i<input.size();i++){
        if(s.size()==0)
            left.push_back(-1);

        else if(s.size()>0 && s.top().first < input[i])
            left.push_back(s.top().second);

        else if(s.size()>0 && s.top().first >= input[i]){
            while(s.size()>0 && s.top().first >= input[i])
                s.pop();
            if(s.size()==0)
                left.push_back(-1);
            else if(s.top().first < input[i])
                left.push_back(s.top().second);
        }
        s.push(make_pair(input[i],i));
    }
    // part2: NSR
    for(int i=input.size()-1;i>=0;i--){
        if(r.size()==0)
            right.push_back(input.size()); //inportant detail

        else if(r.size()>0 && r.top().first < input[i])
            right.push_back(r.top().second);

        else if(r.size()>0 && r.top().first >= input[i]){
            while(r.size()>0 && r.top().first >= input[i])
                r.pop();
            if(r.size()==0)
                right.push_back(input.size());
            else if(r.top().first < input[i])
                right.push_back(r.top().second);
        }
        r.push(make_pair(input[i],i));
    }
    reverse(right.begin(), right.end());

    // part3: area
    for(int i=0;i<left.size();i++){
        area.push_back((right[i] - left[i] - 1) * input[i]);
    }

    cout << "LEFT VECTOR:"<< endl;
    for (int x=0;x<left.size();x++){
        cout << left[x] << " ";
    }
    cout << endl;
    cout << "RIGHT VECTOR:"<< endl;
    for (int x=0;x<left.size();x++){
        cout << right[x] << " ";
    }
    cout << endl;
    cout << "AREA VECTOR:"<< endl;
    for (int x=0;x<left.size();x++){
        cout << area[x] << " ";
        if(area[x]>max)
            max=area[x];
    }
    cout << endl;
    return max;

}

void maximalrectangle(vector<vector<int>> input){
    // break MxN matrix down into M vectors with N elements each
    // think of each row as = row2 hist = row1+row2
    // if row2 element is 0 corresponding row2 hist col=0
    // do MAH on this 
    // ex r1: 0 1 1 0
    //    r2: 1 1 1 1
    //    r3: 1 1 0 0 
    vector<int> sol;
    int max=0;
    for(int i=0;i<input.size();i++){
        for(int j=0;j<input[i].size();j++){
            // row 0
            if(i==0)
                sol.push_back(input[i][j]);
            // all other rows
            else if(i>0){
                // if elem=0
                if(input[i][j]==0)
                    sol[j]=0;
                else if(input[i][j]==1)
                    sol[j] = sol[j]+1;
            }
        }
        if(max < maximumareahistogram(sol))
            max = maximumareahistogram(sol);
        cout << max << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> input1={1,3,0,0,1,2,4};
    vector<int> input2={100,80,60,70,60,75,85};
    vector<int> input3={6,2,5,4,5,1,6};
    vector<vector<int>> matrix
    {
        {0,1,1,0},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,0,0}
    };

    // nextgreatestelement(input1);         //1 (NGR)(NGE)(start from reverse array)
    // previousgreatestelement(input1);     //2 (NGL)(PGE)
    // previoussmallestelement(input1);     //3 (NSL)(PSE)
    // nextsmallestelement(input1);         //4 (NSR)(NSE)(start from reverse array)
    // stockspanproblem(input2);            //5
    // maximumareahistogram(input3);        //6
    // maximalrectangle(matrix);            //7

    return 0;
}