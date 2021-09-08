// NGR
// next largest element OR 
// nearest greater to the right: 
// in an array,find the nearest bigger element
// three cases: 
// either stack empty - push_back -1 to vector and push elem to stack
// stack.top < elem - pop
// stack.top > elem - pushto vector and push elem to stack

//input:  1 3 0 0 1 2 4 
//output: 3 4 1 1 2 4 -1

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int input[]={1,3,0,0,1,2,4};
    int num_elem=sizeof(input)/sizeof(input[1]);

/*
//**********BRUTE FORCE************
    int output[num_elem];
    int elem=0;

    for(int i=0;i<num_elem;i++){
        elem=input[i];
        for(int j=i;j<num_elem;j++){
            if(elem<input[j]){
                output[i]=input[j];                
                break;
            }
            else
                output[i]=-1;
        }
    }
    for(int k=0;k<num_elem;k++){
        // cout << input[k] << endl;
        cout << output[k] << " ";
    }
//***********************************
*/

    vector<int> solution;
    stack<int> s;

    for(int i=num_elem-1;i>=0;i--){
        // stack empty
        if(s.size()==0){
            solution.push_back(-1);
        }
        // stack not empty and top>elem
        else if(s.size()>0 && s.top()>input[i]){
            solution.push_back(s.top());
        }
        // stack not empty and top<elem
        else if(s.size()>0 && s.top()<=input[i]){
            while(s.size()>0 && s.top()<=input[i]){
                s.pop();
            }
            if(s.size()==0){
                solution.push_back(-1);
            }
            else if(s.top()>input[i]){
                solution.push_back(s.top());
            }
        }
        s.push(input[i]);
    }

    for(int x=0;x<solution.size();x++){
        cout << solution[x] << " ";
    }

    cout << "" << endl;
    reverse(solution.begin(),solution.end());

    for(int y=0;y<solution.size();y++){
        cout << solution[y] << " ";
    }

    return 0;
}