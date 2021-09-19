// minimum difference element in sorted array:Given a sorted array, find the element in the array which has minimum difference with the given number
// arr: 4 6 10 elem:7


#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> input{2,4,6,10,15,18};
    int start=0,end,mid=0,target=1,result=0;
    end=input.size()-1;
    
    while(start<=end){
        mid=start+(end-start)/2;
        if(target<input[mid]){
            end=mid-1;
        }
        else if(target>input[mid]){
            start=mid+1;
        }
        else if(target == input[mid]){
            cout << "closest #: " << input[mid] << endl;
            break;
        }
    }

    if(start>end){
        if(abs(input[start]-target) > abs(input[end]-target)){
            cout << "closest #: " << input[end] << endl;
        }
        else
            cout << "closest #: " << input[start] << endl;
    }

    return 0;
}