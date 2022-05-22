// 2 https://leetcode.com/problems/kth-largest-element-in-an-array/
// 3 https://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/
// 4 https://www.geeksforgeeks.org/nearly-sorted-algorithm/
// 5 https://leetcode.com/problems/find-k-closest-elements/
// 6 https://leetcode.com/problems/top-k-frequent-elements/
// 7 https://leetcode.com/problems/sort-array-by-increasing-frequency/
// 8 https://leetcode.com/problems/k-closest-points-to-origin/
// 9 https://www.geeksforgeeks.org/connect-n-ropes-minimum-cost/

#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;

void ksmallestelement(vector<int>& nums, int k){
    priority_queue<int> maxheap;
    for (auto i:nums){
        maxheap.push(i);
        if(maxheap.size()>k)
            maxheap.pop();
    }
    cout << k << " smallest element: " << maxheap.top() << endl;
}

void klargestelement(vector<int>& nums, int k){
    priority_queue<int, vector<int>, greater<int>> minheap;
    for (auto i:nums){
        minheap.push(i);
        if(minheap.size() > k)
            minheap.pop();
    }
    cout << k << " largest element: " << minheap.top() << endl;
}

void ksortedarray(vector<int>& nums, int k){
    // only works if you use minheap
    vector<int> result;
    priority_queue<int, vector<int>, greater<int>> minheap;
    for (int i=0;i<nums.size();i++){
        minheap.push(nums[i]);
        if (minheap.size()>k){
            result.push_back(minheap.top());
            minheap.pop();
        }
    }
    while(minheap.size()>0){
        result.push_back(minheap.top());
        minheap.pop();
    }
    cout << "k sorted array: ";
    for (auto i:result)
        cout << i << " ";
    cout << endl;
}

void kclosestelements(vector<int>& nums, int k, int x){

    priority_queue<pair<int,int>> maxheap;
    for (auto i:nums){
        maxheap.push(make_pair(abs(x-i), i));
        if (maxheap.size()>k)
            maxheap.pop();
    }
    cout << k << " closest elements to " << x << ": ";
    while(maxheap.size()>0){
        cout << maxheap.top().second << " ";
        maxheap.pop();
    }
    cout << endl;
}

void kfrequentnumbers(vector<int>& nums, int k){
#ifndef pp
#define pp pair<int,int>
    priority_queue<pp, vector<pp>, greater<pp>> minheap;
    unordered_map<int,int> mp;

    for(auto i:nums)
        mp[i]++;

    for(auto j=mp.begin();j!=mp.end();j++){
        minheap.push(make_pair(j->second, j->first));
        if(minheap.size()>k)
            minheap.pop();
    }
    cout << k << " most frequent numbers: ";
    while(minheap.size()>0){
        cout << minheap.top().second << " ";
        minheap.pop();
    }
    cout << endl;
#endif
}

void sortarraybyfreq(vector<int>& nums){

    priority_queue<pp> maxheap;
    unordered_map<int,int> mp;

    for(auto i:nums)
        mp[i]++;

    for(auto j=mp.begin();j!=mp.end();j++){
        maxheap.push(make_pair(j->second,j->first));
    }
    cout <<"frequency sorted array: ";
    while(maxheap.size()>0){
        cout << maxheap.top().second << " ";
        maxheap.pop();
    }
    cout << endl;
}

void kclosetoorigin(vector <vector<int>>& nums, int k){
    int dist;
    priority_queue<pair<int, pair<int,int>>> maxheap;
    for(int i=0;i<nums.size();i++){
        dist = 0;
        for(int j=0;j<nums[i].size();j++){
            dist = sqrt(nums[i][j]*nums[i][j] + dist*dist);
        }
        maxheap.push(make_pair(dist, make_pair(nums[i][0],nums[i][1])));
        if(maxheap.size()>k)
            maxheap.pop();
    }
    cout << k << " closest points: ";
    while(maxheap.size()>0){
        cout << maxheap.top().second.first << "," << maxheap.top().second.second << " ";
        maxheap.pop();
    }
    cout << endl;
}

int main(){
    vector <int> nums1 = {7,10,4,3,20,15};
    vector <int> nums2 = {6,5,3,2,8,10,9};
    vector <int> nums3 = {1,6,3,9,12,7,5};
    vector <int> nums4 = {1,1,1,12,12,12,2,2,2,3,3,4,7,7,9,9,9,9,13,14};
    vector <vector<int>> nums5
    {
        {3,3},
        {5,-1},
        {-2,4}
    };
    
    int k = 2;
    int x = 4;
    // ksmallestelement(nums1, k);      //2
    // klargestelement(nums1, k);       //2
    // ksortedarray(nums2, k);          //4
    // kclosestelements(nums3, k, x);   //5
    // kfrequentnumbers(nums4, k);      //6
    // sortarraybyfreq(nums4);          //7 (TODO: answer is 14,13,4,7,3,12,2,1,9)
    kclosetoorigin(nums5, k);

}