// peak element: A peak element is an element that is strictly greater than its neighbors.
// https://leetcode.com/problems/find-peak-element/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> input {1,2,1,3,5,6,4};
    int start=0,end,mid=0,prev=0,next=0;
    end = input.size()-1;

    while(start<=end){
        mid = start+(end-start)/2;
        prev=mid-1;
        next=mid+1;
        if(input.size()==1){
            cout << "peak element: " << input[mid] << endl;
            break;
        }
        // if mid first elem
        else if(mid==0){
            if(input[mid]>input[next]){
                cout << "peak element: " << input[mid] << endl;
            }
            else{
                cout << "peak element: " << input[next] << endl;
            }
            break;
        }
        // if mid=last elem
        else if(mid==input.size()-1){
            if(input[mid]>input[prev]){
                cout << "peak element: " << input[mid] << endl;
            }
            else{
                cout << "peak element: " << input[prev] << endl;
            }
            break;
        }

        else{
            // if both left and right big, done
            if(input[prev]<input[mid] && input[next]<input[mid]){
                cout << "peak element: " << input[mid] << endl;
                break;
            }
            // if prev element bigger, move left based on promising nature
            else if(input[prev]>input[mid]){
                end=mid-1;
            }
            // else move right if next element bigger
            else if(input[next]>input[mid]){
                start=mid+1;
            }
        }
    }
    return 0;
}