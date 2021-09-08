// kth smallest element: return the 3rd smallest element in a given input

// arr[]: 7 10 4 3 20 15  
// k is 3
// find the 3rd smallest element

#include <functional>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;


int main()
{
    cout << "kth smallest element in array" << endl;
    int k=3;
    int arr[] = {7,10,4,3,20,15};
    priority_queue<int> maxheap;
    int num_elements = sizeof(arr)/sizeof(int);

    for (int i=0;i<num_elements;i++){
        maxheap.push(arr[i]);
        if (maxheap.size()>k){
            maxheap.pop();
        }
    }
    int result = maxheap.top();
    cout << result << endl;
    return 0;
}