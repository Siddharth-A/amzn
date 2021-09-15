// search in nearly sorted array:
// https://www.geeksforgeeks.org/search-almost-sorted-array/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    // vector<int> input{5,10,30,20,40};
    vector<int> input{10, 3, 40, 20, 50, 80, 70};
    int target=50;
    int start=0,mid=0,prev,next;
    int end=input.size()-1;

    while(start<=end){
        mid=start+(end-start)/2;
        prev=mid-1;
        next=mid+1;
        // cout << start << " " << prev << " " << mid << " " << next << " " << end << endl;
        if(input[mid]==target){
            cout << mid << endl;
            break;
        }
        else if(input[prev]==target){
            cout << prev << endl;
            break;
        }
        else if(input[next]==target){
            cout << next << endl;
            break;
        }
        else if(input[mid]>target){
            end=mid-2;
        }
        else if(input[mid]<target){
            
            start=mid+2;
        }

    }

    return 0;
}


