// next alphabet: Given an array of letters sorted in ascending order, find the smallest letter in the the array which is greater than a given key letter
// https://leetcode.com/problems/find-smallest-letter-greater-than-target/

// changes: 
// even if elem = input[mid], we move to right
// if target > input, no change
// else if target < input, result=input[mid], end=mid-1

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<char> input {'a','c','f','h','j','l','m'};
    char target='m';

    int start=0,end,mid=0,result;
    char res;
    end = input.size()-1;

    while(start<=end){
        mid = start + (end-start)/2;
        if(target > input[mid]){
            start=mid+1;
        }
        else if(target < input[mid]){
            res = input[mid];
            result=mid;
            end = mid-1;
        }
        else if(target == input[mid]){
            start=mid+1;
        }
        
    }

    cout << res << endl;

    return 0;
}
