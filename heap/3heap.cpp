// return K largest elements in array: return the 3 largest elements in an input

// min heap - smallest element on top

#include <functional>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;


int main()
{
    int arr[] = {7,10,4,3,20,15};
    int num_elements = sizeof(arr)/sizeof(int);
    int k = 3;
    priority_queue<int,vector<int>,greater<int>> minheap;

    for (int i=0;i<num_elements;i++){
        minheap.push(arr[i]);

        if (minheap.size() > k){
            minheap.pop();
        }
    }

    int x = 1;
    while (minheap.size() > 0){
        cout << x << " largest int: " << minheap.top() << endl;
        minheap.pop();
        x++;
    }

    return 0;
}