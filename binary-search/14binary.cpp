// find index of 1st 1 in binary sorted array
// https://www.geeksforgeeks.org/find-index-first-1-sorted-array-0s-1s/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> input{0,0,0,0,0,0,0,0,0,1,1};
    int start=0,mid=0,end,target=1,result=0;
    end=input.size()-1;
    

    while(start<=end){
        mid=start+(end-start)/2;
        if(input[mid]==0){
            start = mid+1;
        }
        else if(target==1 && input[mid-1]!=1){
            cout << "position of first 1: " << mid << endl;
            break;
        }
        else if(input[mid]==1){
            end=mid-1;
        }
    }

    return 0;
}