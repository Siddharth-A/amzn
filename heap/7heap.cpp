// frequency sort: sort entire array with most frequent element the first element

// arr: 1 1 1 3 2 2 4 6 6
// entire array will be sorted
// output: 1,1,1,2,2,6,6,3,4
// use max heap here

#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <cmath>
#include <unordered_map>

#define ppi pair<int,int>

using namespace std;


int main()
{
    int arr[]={1,1,1,3,2,2,4,6,6};
    int num_elem=sizeof(arr)/sizeof(arr[1]);
    unordered_map<int,int> mp;
    priority_queue<ppi> maxheap;
    
    for(int i=0;i<num_elem;i++){
        mp[arr[i]]++;
    }

    for(auto j=mp.begin();j!=mp.end();j++){
        maxheap.push(make_pair(j->second,j->first));
    }

    cout << "sorted array: ";
    while(maxheap.size()>0){
        int freq=maxheap.top().first;
        int elem=maxheap.top().second;
        for(int l=0;l<freq;l++){
            cout << elem << " ";
        }
        maxheap.pop();
    }
}
