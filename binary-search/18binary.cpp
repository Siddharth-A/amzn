// find max element in bitnoic array
// https://www.geeksforgeeks.org/find-the-maximum-element-in-an-array-which-is-first-increasing-and-then-decreasing/

// diff edge cases: 
//                  1.first elem is max 
//                  2.last elem is max 
//                  3.element in middle is max 
//                  4.duplicate elements
//                  5.array size = 1

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> input {10,12,15,17,23,2,5,7,9};
    int start=0,end,mid=0;
    end=input.size()-1;

    if(end==0){
        cout << "max element is the only elem in array: " << input[end] << endl;
        return 0;
    }
    if(input[start]>input[start+1]){
        cout << "max element in array is: " << input[start] << endl;
        return 0;
    }

    while(start<=end){
        mid=start+(end-start)/2;
        int next=mid+1;
        int prev=mid-1;
        if(input[mid]>input[next] && input[mid]>input[prev]){
            cout << "max element in array is: " << input[mid] << endl;
            break;
        }
        // the order matters. always check if prev elem is bigger first
        else if(input[mid]<input[prev]){
            end=mid-1;
        }
        else if(input[mid]<input[next]){
            start=mid+1;
        }
    }

    return 0;
}