// binary search: given a sroted array, find and return index of given #
// https://leetcode.com/problems/binary-search/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> nums {1,2,3,4,5,6,7,8,9,10};
    int target=7;
    int mid,start=0;
    int end=nums.size()-1;

    while(start<=end){
        mid = start+(end-start)/2;
        if(target<nums[mid]){
            end=mid-1;
        }
        else if(target>nums[mid]){
            start=mid+1;
        }
        else if(target == nums[mid]){
            cout << "index of target: " << mid << endl;
            break;
        }
    }
    if(target!=nums[mid]){
        cout << "target not found in nums" << endl;
    }

    return 0;
}