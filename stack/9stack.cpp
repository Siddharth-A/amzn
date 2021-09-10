// trapping rain water: given an array of elevation map where width of each bar is 1, calculate how much rain water can be trapped in between 
// https://leetcode.com/problems/trapping-rain-water/

// 3 0 0 2 0 4
// water[i] = sum(min[maxleft,maxright] - input[i])
// maxleft = max elem on left side of i
// maxright= max elem on right side of i

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
    vector<int> input{3,0,0,2,0,4};
    stack<int> s;
    vector<int> sol;
    vector<int> maxleft;
    vector<int> maxright;
    int mxl=0;
    int mxr=0;
    int temp,water=0;

    // maxleft
    for(int i=0;i<input.size();i++){
        if(input[i]>mxl){
            mxl=input[i];
        }
        maxleft.push_back(mxl);
    }

    // maxright
    for(int j=input.size()-1;j>=0;j--){
        if(input[j]>mxr){
            mxr=input[j];
        }
        maxright.push_back(mxr);
    }
    reverse(maxright.begin(),maxright.end());

    // solution
    for(int x=0;x<input.size();x++){
        temp = min(maxleft[x],maxright[x]) - input[x];
        water = water + temp;
    }
    cout << "total rain water trapped: " << water << endl;
    
    return 0;
}