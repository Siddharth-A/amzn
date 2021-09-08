// top K frequent numbers: find k numbers which repeat the most

// create unordered map which will store frequency of each int occourence
// in the unordered map, key is the array element and value is the occurence off array element
// use the frequency as key and create a hashmap 
// 1 1 1 3 2 2 4 6 6 6
// min heap

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
    int k=3;
    int arr[]={1,1,1,3,2,2,4,6,6,6};
    int num_elem=sizeof(arr)/sizeof(arr[1]);
    
    unordered_map<int,int> mp;
    for(int i=0;i<num_elem;i++){
        mp[arr[i]]++;
    }
    
    priority_queue<ppi,vector<ppi>,greater<ppi>> minheap;

    for(auto j=mp.begin();j!=mp.end();j++){
        minheap.push(make_pair(j->second,j->first));
        if (minheap.size()>k){
            minheap.pop();
        }
    }
    cout << k << " most occuring elements in array are: " << endl;
    while (minheap.size()>0){
        cout << minheap.top().second << " which occured " << minheap.top().first << " times" << endl;
        minheap.pop();
    }
}