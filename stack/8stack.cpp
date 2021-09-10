// Max area rectangle in binary matrix: Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
// https://leetcode.com/problems/maximal-rectangle/

// 0 1 1 0
// 1 1 1 1 
// 1 1 1 1
// 1 1 0 0 
// break into 4 histograms and apply MAH on each histogram
// max of MAH answer is max area possible in matrix

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define ppi pair<int,int>

using namespace std;

int maxareahist(vector<int>& input){
    // NSL
    vector<int> left;
    vector<int> right;
    stack<ppi> s;
    vector<int> sol;
    int area=0;
    int temp=0;

    for (int i=0;i<input.size();i++){
        // stack null
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
                if(s.size()==0){
                    left.push_back(-1);
                }
                else if(s.top().first<input[i]){
                    left.push_back(s.top().second);
                }
            }
        }
        s.push(make_pair(input[i],i));
    }

    while(s.size()>0){
        s.pop();
    }

    for (int i=input.size()-1;i>=0;i--){
        // stack null
        if(s.size()==0){
            right.push_back(input.size());
        }
        // s.top()<input[i]
        else if(s.top().first<input[i]){
            right.push_back(s.top().second);
        }
        // s.top()>input[i]
        else if(s.top().first>=input[i]){
            while(s.size()>0 && s.top().first>=input[i]){
                s.pop();
                if(s.size()==0){
                    right.push_back(input.size());
                }
                else if(s.top().first<input[i]){
                    right.push_back(s.top().second);
                }
            }
        }
        s.push(make_pair(input[i],i));
    }
    reverse(right.begin(),right.end());

    // width = (right-left)-1
    // area = width*input[i]
    for (int x=0;x<left.size();x++){
        area=((right[x]-left[x])-1)*input[x];
        sol.push_back(area);
        // cout << sol[x] << " ";
        if (temp<sol[x])
            temp=sol[x];
    }
    
    return temp;
}

int main(){
    
    vector<vector<int>> input{
        {0,1,1,0},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,0,0}
    };

    vector<int> h;
    int max=0;

    for(int i=0;i<input.size();i++){
        for(int j=0;j<input[i].size();j++){
            // if first line of matrix
            if(i==0){
                cout << "l0 ";
                h.push_back(input[0][j]);
                cout << h[j] << " ";
            }
            // if line is not first line
            else if(i>0){
                if(input[i][j]==0){
                    cout << "l" << i << " ";
                    h[j] = 0;
                }
                
                else if (input[i][j]!=0){
                    cout << "l" << i << " ";
                    h[j] = h[j]+input[i][j];
                }
                    
                cout << h[j] << " ";
            }
        }
        if(max<maxareahist(h)){
            max = maxareahist(h);
        }
        cout << "\n";
    }
    cout << max << endl;
    return 0;
}