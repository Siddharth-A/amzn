// 1  https://leetcode.com/problems/binary-search/
// 2  reverse binary search
// 4  https://www.geeksforgeeks.org/order-agnostic-binary-search/
// 5  https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// 7  https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// 9  https://www.geeksforgeeks.org/search-almost-sorted-array/
// 10 https://www.geeksforgeeks.org/floor-in-a-sorted-array/
// 12 https://leetcode.com/problems/find-smallest-letter-greater-than-target/
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

void firstlastpositions(vector<int> input, int target){
    int start=0;
    int mid=0;
    int first=0;
    int last=0;
    int end=input.size()-1;

    while(start <= end){
        mid = start + (end-start)/2;
        if(target < input[mid])
            end = mid-1;

        else if(target > input[mid])
            start = mid+1;

        else if(target == input[mid]){
            last = mid;
            while(input[last] == input[last+1])
                last = last+1;
            
            first = mid;
            while(input[first] == input[first-1])
                first = first-1;

            break;
        }
    }
    cout << "target: " << target << " first occ: " << first << " last occ: " << last << endl;
}

void rotatedarrayminelem(vector<int> input){
    int start=0;
    int mid=0;
    int end=input.size()-1;
// find min elem in rotated array
// ex: 6,1,2,3,4,5 => answer is 1
// ex2: 2,3,4,5,6,1 => answer is 1

// criteria for target: mid-1 > mid & mid < mid+1
// left: go left when   end > mid
// right: go right when start > mid
    while(start <=end){
        mid = start + (end-start)/2;
        if(input[mid-1]>input[mid] && input[mid]<input[mid+1]){
            cout << "hit3" << endl;
            cout << "min element: " << input[mid] << endl;
            break;
        }

        else if(input[start]<input[mid]){ //right
            start = mid+1;
            cout << "hit1" << endl;
        }

        else if(input[end]>input[mid]){ //left
            end = mid-1;
            cout << "hit2" << endl;
        }
    }

}

void nearlysortedarray(vector<int> input, int target){
    int start=0;
    int mid=0;
    int prev=0;
    int next=0;
    int end=input.size()-1;

    while(start<=end){
        mid=start+(end-start)/2;
        prev=mid-1;
        next=mid+1;

        if(target == input[mid]){
            cout << "target index: " << mid << endl;
            break;
        }
        else if(target == input[mid-1]){
            cout << "target index: " << mid-1 << endl;
            break;
        }
        else if(target == input[mid+1]){
            cout << "target index: " << mid+1 << endl;
            break;
        }

        else if(target < input[mid])
            start = mid+2;

        else if(target > input[mid])
            end = mid-2;
    }
}

void floorofelement(vector<int> input, int target){
    // store element in temp every time you move right
    int start=0; int mid=0; int end=input.size()-1;
    int temp=0;

    while(start<=end){
        mid = start + (end-start)/2;
        if(target < input[mid])
            end = mid-1;

        else if(target > input[mid]){
            start = mid+1;
            temp = input[mid];
        }

        else if(target == input[mid]){
            temp = input[mid];
            break;
        }
    }
    cout << "floor of target " << target << " is: " << temp << endl;
}

void nextgreatestletter(vector<char> input, char target){
    // store input[mid] into temp when going left
    int start=0; int mid=0; int end=input.size()-1;
    char temp;

    while(start<=end){
        mid = start+(end-start)/2;
        if(target < input[mid]){
            end=mid-1;
            temp = input[mid];
        }

        else if(target > input[mid]){
            start=mid+1;
        }

        else if(target == input[mid])
            start=mid+1;
        
        if((end<=0) | (start>=input.size())){
            temp=input[0];
            break;
        }
    }
    cout << "ceiling of target " << target << " is: " << temp << endl;
}

int main(){
    vector<int> input1 = {-1,0,3,5,9,12};
    int t1 = 12;
    vector<int> input2 = {88,76,45,23,-11,-30,-63};
    int t2 = -30;
    vector<int> input3 = {40,10,5,2,1};
    int t3 = 2;
    vector<int> input4{2,4,10,10,10,18,20};
    int t4 = 10;
    vector<int> input5{11,12,15,18,2,5,6,8};
    vector<int> input6{10,3,40,20,50,80,70};
    int t6 = 40;
    vector<int> input7{1,2,3,4,8,10,10,12,19};
    int t7=18;
    vector<char> input8{'a','b','c','f','h','j','l','m'};
    char t8='g';

    // int x = simplebinarysearch(input1, t1);      // 1
    // int y = reversebinarysearch(input2, t2);     // 2
    // agnosticbinarysearch(input3, t3);            // 4
    // firstlastpositions(input4, t4);              // 5
    // rotatedarrayminelem(input5);                 // 7
    // nearlysortedarray(input6, t6);               // 9
    // floorofelement(input7,t7);                   // 10
    // nextgreatestletter(input8, t8);              // 12

    return 0;
}