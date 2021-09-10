// maximum area of histogram: given an array of heights representing histograms bar height, return area of largest rectangle if width of each bar is 1
// https://leetcode.com/problems/largest-rectangle-in-histogram/

// arr[] = 6 2 5 4 5 1 6
// to find the width the rectangle will span across, you need to find two points
// first point: smaller element on left     NSL
// second point: smaller element on right   NSR
// then subtract the above points and multiply with element value
// for ex: for 4: smaller element to left: 2(index:1) smaller element to right: 1(index:5)
// area of rectangle = ((5-1)-1)*4 = 12
// also create two pseudo indexes= 0 for NSL and 7 for NSR

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

#define ppi pair<int,int>

using namespace std;

int main(){
    int input[]={6,2,5,4,5,1,6};
    int num_elem=sizeof(input)/sizeof(input[1]);
    stack<ppi> s;
    vector<int> left;
    vector<int> right;
    vector<int> sol;
    int temp=0;
    int max=0;

    // NSL
    for(int i=0;i<num_elem;i++){
        // null stack
        if(s.size()==0){
            left.push_back(-1);
        }
        // s.top()<input[i]
        else if(s.top().first<input[i]){
            left.push_back(s.top().second);
        }
        // s.top()>input[i]
        else if(s.top().first>=input[i]){
            while(s.size()>0 && s.top().first>=input[i]){
                s.pop();
            }
            if(s.size()==0){
                left.push_back(-1);
            }
            else if(s.top().first<input[i]){
                left.push_back(s.top().second);
            }
        }
        s.push(make_pair(input[i],i));
    }

    while(s.size()>0){
        s.pop();
    }

    // NSR
    for(int j=num_elem-1;j>=0;j--){
        // null stack
        if(s.size()==0){
            right.push_back(num_elem);
        }
        // s.top()<input[j]
        else if(s.top().first<input[j]){
            right.push_back(s.top().second);
        }
        // s.top()>input[j]
        else if(s.top().first>=input[j]){
            while(s.size()>0 && s.top().first>=input[j]){
                s.pop();
            }
            if(s.size()==0){
                right.push_back(num_elem);
            }
            else if(s.top().first<input[j]){
                right.push_back(s.top().second);
            }
        }
        s.push(make_pair(input[j],j));
    }
    reverse(right.begin(),right.end());

    cout << "LEFT VECTOR:"<< endl;
    for (int x=0;x<left.size();x++){
        cout << left[x] << " ";
    }
    cout << "\n";
    cout << "RIGHT VECTOR:"<< endl;
    for (int x=0;x<left.size();x++){
        cout << right[x] << " ";
    }
    cout << "\n";
    cout << "AREA VECTOR:"<< endl;
    for (int x=0;x<left.size();x++){
        temp=((right[x]-left[x])-1)*input[x];
        sol.push_back(temp);
        cout << sol[x] << " ";
        if(sol[x]>max)
            max=sol[x];
    }
    cout << endl << "MAX AREA: " << max << endl;
    return 0;
}