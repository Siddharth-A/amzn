// K closest number: given k=3 and x=7. find k closest # to x

// 5 6 7 8 9
// subtract all entried by x
// 2 1 0 1 2
// max heap of the difference but need two values in heap now



#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;


int main()
{
    int k=3;
    int x=7;
    int arr[]={4,5,6,7,8,9,10};
    int num_elem=sizeof(arr)/sizeof(arr[1]);
    priority_queue<pair<int,int>> maxheap;

    for (int i=0;i<num_elem;i++){
        maxheap.push(make_pair(abs(arr[i]-x),arr[i]));
        if(maxheap.size()>k){
            maxheap.pop();
        }
    }
    cout << k << " closest numebers to " << x << " are: " << endl;
    while(maxheap.size()>0){
        cout << maxheap.top().second << endl;
        maxheap.pop();
    }
}