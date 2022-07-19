// 1 https://leetcode.com/problems/binary-search/
// 2 reverse binary search
// 4 https://www.geeksforgeeks.org/order-agnostic-binary-search/
// 5 https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// 6
// 7
// 8
// 9
// 10
// 11
// 12
// 13
// 14
// 15
// 16
// 17
// 18
// 19

/*!
* \brief -  if input is sorted in ascending/descening manner, then binary search is always warranted

step 1: figure out when code should stop (while loop)
step 2: figure out triggers for code to go left or right
step 3: check for edge cases 
*/

#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;

int simplebinarysearch(vector<int> input, int target){
    int start = 0;
    int end = input.size() - 1;
    int mid = 0;

    while(start <= end){
        mid = start + (end-start)/2;
        if(target < input[mid])
            end = mid-1;

        else if(target > input[mid])
            start = mid+1;

        else if(target == input[mid]){
            cout << "target: " << input[mid] << " index: " << mid << endl;
            break;
        }
    }
    return mid;
}

int reversebinarysearch(vector<int> input, int target){
    int start, mid = 0;
    int end = input.size()-1;

    while(start<=end){
        mid = start + (end-start)/2;
        if(target < input[mid])
            start=mid+1;

        else if(target > input[mid])
            end=mid-1;

        else if(target==input[mid]){
            cout << "target: " << input[mid] << " index: " << mid << endl;
            break;
        }
    }
    return mid;
}

void agnosticbinarysearch(vector<int> input, int target){
    int start = 0;
    int mid = 0;
    int end = input.size()-1;
    int x = 999;

    if(input[start] > input[end]){
        cout << "input is descending order" << endl;
        x = reversebinarysearch(input,target);
    }
    else if(input[start] < input[end]){
        cout << "input is ascending order" << endl;
        x = simplebinarysearch(input,target);
    }
}

int main(){
    vector<int> input1 = {-1,0,3,5,9,12};
    int t1 = 12;
    vector<int> input2 = {88,76,45,23,-11,-30,-63};
    int t2 = -30;
    vector<int> input3 = {40,10,5,2,1};
    int t3 = 2;

    // int x = simplebinarysearch(input1, t1);      // 1
    // int y = reversebinarysearch(input2, t2);     // 2
    // agnosticbinarysearch(input3, t3);            // 4
    // firstlastpositions(input4, t4);              // 5

    return 0;
}