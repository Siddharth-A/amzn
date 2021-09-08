// connected ropes: given an arr of rope size, minimize the cost to join all of them

// arr[]=1 2 3 4 5 
// cost = sum of two ropes in each step 
// trick is to add two min nums
// method1: 1 2 3 4 5 = 1+2 3 4 5 c:3 | 3+3 4 5 c:6 | 6+4 5 c:10 | 10+5 c:15 total c:34
// method2: 1 2 3 4 5 = 1+2 3 4 5 c:3 | 3+3 4 5 c:6 | 6 4+5 c:19 | 10+5 c:15 total c:33

#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;

int main(){
    vector<int> ropes{1,2,3,4,5};
    priority_queue<int, vector<int>,greater<int>> minheap;
    int cost=0;
    int tcost=0;
    int rope1=0;
    int rope2=0;

    for(int i=0;i<ropes.size();i++){
        minheap.push(ropes[i]);
    }
    while(minheap.size()>1){
        rope1=minheap.top();
        cout << "rope1: "<< rope1 << endl;
        minheap.pop();
        rope2=minheap.top();
        cout << "rope2: " << rope2 << endl;
        minheap.pop();
        cost = rope1+rope2;
        minheap.push(cost);
        tcost=cost+tcost;
        cout << "cost: " << tcost << endl;
    }

    return 0;
}
