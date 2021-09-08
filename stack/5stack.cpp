// 

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
    int input[]={4,5,2,10,8};
    int num_elem=sizeof(input)/sizeof(input[1]);
    stack<int> s;
    vector<int> v;

    for(int i=num_elem-1;i>=0;i--){
        // null stack
        if(s.size()==0){
            v.push_back(-1);
        }
        // s.top < input[i]
        else if(s.top()<input[i]){
            v.push_back(s.top());
        }
        // s.top > input[i]
        else if(s.top()>=input[i]){
            while(s.size()>0 && s.top()>=input[i]){
                s.pop();
            }
            if(s.size()==0){
                v.push_back(-1);
            }
            else if(s.top()<input[i]){
                v.push_back(s.top());
            }
        }
        s.push(input[i]);
    }

    for (int x=0;x<v.size();x++){
        cout << v[x] << " ";
    }
    cout << "\n";
    reverse(v.begin(),v.end());

    for (int x=0;x<v.size();x++){
        cout << v[x] << " ";
    }

    return 0;
}