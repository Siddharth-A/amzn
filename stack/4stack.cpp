// NSL
// nearest smaller to left

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int input[]={4,5,2,10,8};
    int num_elem=sizeof(input)/sizeof(input[1]);
    stack<int> s;
    vector<int> sol;

    for(int i=0;i<num_elem;i++){
        // null stack
        if(s.size()==0){
            sol.push_back(-1);
        }
        // s.top < input[i]
        else if(s.top()<input[i]){
            sol.push_back(s.top());
        }
        // s.top > input[i]
        else if(s.top()>=input[i]){
            while(s.size()>0 && s.top()>=input[i]){
                s.pop();
            }
            if(s.size()==0){
                sol.push_back(-1);
            }
            else if(s.top()<input[i]){
                sol.push_back(s.top());
            }
        }
        s.push(input[i]);
    }
    // reverse(sol.begin(),sol.end());
    for (int x=0;x<sol.size();x++){
        cout << sol[x] << " ";
    }
    return 0;
}
