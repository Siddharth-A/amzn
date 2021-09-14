// order agnostic search: given a sorted array, find target element. we do not know if sorted ascending or descending

#include <iostream>
#include <vector>

using namespace std;

int main(){
    // vector<int> input{7,6,5,4,3,2,1,0};
    vector<int> input{1,2,3,4,5,6,7,8,9,10};
    int end,mid,start=0,target=10;
    end = input.size()-1;

    while(start <= end){
        mid = start + (end-start)/2;
        
        if(input[start] > input[end]){
            // descending
            if(target<input[mid]){
                start = mid+1;
            }
            else if(target>input[mid]){
                end = mid-1;
            }
            else if(target == input[mid]){
                cout << "index of target: " << mid << endl;
                break;
            }
        }
        else if(input[start] < input[end]){
            // ascending
            if(target<input[mid]){
                end = mid-1;
            }
            else if(target>input[mid]){
                start = mid+1;
            }
            else if(target == input[mid]){
                cout << "index of target: " << mid << endl;
                break;
            }
        }

        else if(input[start] == input[end]){
            cout << "index of target: " << mid << endl;
            break;
        }
    }
    if(target != input[mid]){
        cout << "target not found" << endl;
    }
    return 0;
}