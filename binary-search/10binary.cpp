// floor of an element in sorted array:
// https://www.geeksforgeeks.org/floor-in-a-sorted-array/

// 1 2 3 4 8 10 10 12 19
// elem = 5 
// floor is 4

#include <iostream>
#include <vector>

using namespace std;

int main(){
    // vector<int> input{5,10,30,20,40};
    vector<int> input{1,2,3,4,8,10,10,12,19};
    int target=20;
    int start=0,mid=0,result=0;
    int end=input.size()-1;

    while(start <= end){
        mid = start + (end-start)/2;
        if(target < input[mid]){
            end = mid-1;
        }
        else if(target > input[mid]){
            start=mid+1;
            result=mid;
            cout << "floor of input: " << input[result] << endl;
        }
        else if(target == input[mid]){
            cout << "floor of input: " << input[mid] << endl;
            break;
        }
    }

    return 0;
}