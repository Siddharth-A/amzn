// search in bitonic sorted array: 
// input:1 3 8 12 4 6 target:4

// cases:
//      1.array size is 1
//      2.target not in array
//      3.target is last elem
//      4.target is first elem
//      5.target in some other pos
// how to go left and right?
// divide array in to two parts. part1:ascending array  part2:descending array

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> input{2,4,6,8,23,34,11,10,7,3};
    int start=0,mid=0,end,prev=0,next=0,target=10;
    end=input.size()-1;

    if(end==0){
        cout << "max element is the only elem in array: " << input[end] << endl;
        return 0;
    }

    while(start<=end){

    }

    if(start>end){
        cout << "element not found" << endl;
    }

    return 0;
}