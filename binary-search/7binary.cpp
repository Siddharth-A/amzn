// number of times array rotated:
// https://www.geeksforgeeks.org/find-rotation-count-rotated-sorted-array/
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

// 2 5 6 8 11 12 15 18
// 11 12 15 18 2 5 6 8 -> num of rotations: 4 (index of smallest elem)
// criteria to find elem: mid-1 > mid < mid+1
// criteria to move:
// if start > mid: end=mid-1
// if end < mid: start=mid+1

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> input{11,12,15,18,2,5,6,8};
    int end,mid,start=0,prev,next;
    end = input.size()-1;
    int size = input.size();


    if(input[start]<input[end]){
        cout << "array rotation: 0" << endl;
    }
    while(start<=end){
        mid = start+(end-start)/2;
        prev=(mid+size-1)%size;
        next=(mid+1)%size;

        if(input[mid]<input[prev] && input[mid]<input[next]){
            cout << "array rotation: " << mid << endl;
            break;
        }
        else if(input[start]<=input[mid]){
            start=mid+1;
        }
        else if(input[end]>=input[mid]){
            end=mid-1;
        }
        cout << prev << " " << mid << " " << next << " " << start << " " << end << " " << endl;
    }

    return 0;
}
