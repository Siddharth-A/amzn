// sort a K sorted array: in given array, the element is K away from where it should be if sorted

// 6 5 3 2 8 10 9
// you only need to look at 1+k elements in array at one time. so 
// 6 5 3 2 => pop 2 and make it arr[0] element
// 6 5 3 8 => pop 3
// 6 5 8 10 =? pop 5 
// 6 8 10 9=? pop 6
// k=3

#include <functional>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;


int main()
{
    int arr[]={6,5,3,2,8,10,9};
    int num_elem=sizeof(arr)/sizeof(arr[1]);
    int new_arr[num_elem]={};
    int j=0;
    int k=3;
    priority_queue <int,vector<int>,greater<int>> minheap;

    for(int i=0;i<num_elem;i++){
        minheap.push(arr[i]);
        if(minheap.size()>(k)){
            new_arr[j]=minheap.top();
            minheap.pop();
            j++;
        }
    }
    while(minheap.size()>0){
        new_arr[j]=minheap.top();
        minheap.pop();
        j++;
    }

    cout << "sorted array: " << endl;
    for(int k=0;k<num_elem;k++){
        cout << new_arr[k] << " ";
    }
    cout << "\n" << endl;
    return 0;
}