// stock span problem: given input array of daily stock price, output array with # of days previously the stock price was lower than current price
// https://leetcode.com/problems/online-stock-span/

// TO FIND CONSECUTIVE SMALLER OR = ELEM BEFORE IT == NEAREST GREATER ELEMENT FROM LEFT
// 100 80 60 70 60 75 85
// 1   1  1  2  1  4  6
// for 75: 60/70/60 and 75 itself
// using NGL, look for nearest greater elem starting from left and store its index in another vector
// input arr                                            :100 | 80 | 60 | 70 | 60 | 75 | 85
// index of nearest greater or equal starting from right: -1 |  0 |  1 |  1 |  3 |  1 | 0
// subtract index - vec[i]                              :  1 |  1 |  1 |  2 |  1 |  4 | 6
 
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

#define ppi pair<int,int>

using namespace std;

int main(){
    int input[]={100,80,60,70,60,75,85};
    int num_elem=sizeof(input)/sizeof(input[1]);
    // stack contains element and its index
    stack<ppi> s;
    vector<int> v1;
    vector<int> span;

    for(int i=0;i<num_elem;i++){
        // stack is null
        if (s.size()==0){
            v1.push_back(-1);
        }
        // s.top()>input[i]
        else if(s.top().first>input[i]){
            v1.push_back(s.top().second);
        }
        // s.top()<=input[i]
        else if(s.top().first<input[i]){
            while(s.size()>0 && s.top().first<input[i]){
                s.pop();
            }
            if(s.size()==0){
                v1.push_back(-1);
            }
            else if(s.top().first>input[i]){
                v1.push_back(s.top().second);
            }
        }
        s.push(make_pair(input[i],i));
    }
    for (int x=0;x<v1.size();x++){
        // cout << v1[x] << " ";
        span.push_back(x-v1[x]);
        cout << span[x] << " ";
    }

    return 0;
}