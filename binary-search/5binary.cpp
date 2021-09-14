// first and last occurence of element:Given a sorted array with possibly duplicate elements find indexes of first and last occurrences of an element x in the given array.
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/


#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> input{2,4,10,10,10,18,20};
    int end,mid,start=0,target=10,first_occur=0,last_occur=0;
    end = input.size()-1;

    // first occurence search
    while(start<=end){
        mid = start + (end-start)/2;
        if(target<input[mid]){
            end = mid-1;
        }
        else if(target>input[mid]){
            start = mid+1;
        }
        else if(input[mid] == target){
            first_occur = mid;
            end = mid - 1;
        }
    }
    start=0;
    end=input.size()-1;
    // last occurence search
    while(start<=end){
        mid = start + (end-start)/2;
        if(target<input[mid]){
            end = mid-1;
        }
        else if(target>input[mid]){
            start = mid+1;
        }
        else if(input[mid] == target){
            last_occur = mid;
            start = mid + 1;
        }
    }
    cout << first_occur << " " << last_occur << endl;
    return 0;
}