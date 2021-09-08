// NGL
// nearest greater to left


#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int input[]={1,3,0,0,1,2,4};
    int num_elem=sizeof(input)/sizeof(input[1]);
    stack<int> s;
    vector<int> sol;

    for(int i=0;i<num_elem;i++){
        // stack empty
        if(s.size()==0){
            sol.push_back(-1);
        }
        // s.top > elem
        else if(s.size()>0 && s.top()>input[i]){
            sol.push_back(s.top());
        }
        // s.top < elem
        else if(s.size()>0 && s.top()<=input[i]){
            while(s.size()>0 && s.top()<=input[i]){
                s.pop();
            }
            if(s.size()==0){
                sol.push_back(-1);
            }
            else if(s.top()>input[i]){
                sol.push_back(s.top());
            }
        }
        s.push(input[i]);
    }

    // reverse(sol.begin(),sol.end());

    for(int x=0;x<sol.size();x++){
        cout << sol[x] << " ";
    }
    cout << "\n";

    return 0;
}