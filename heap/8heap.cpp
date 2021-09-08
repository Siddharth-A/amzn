// K closest points to origin: given a 2x2 matrix of x,y cordinates find k closest points to origin

// k=2 
// arr[][]={{1,3},{-2,2},{5,8},{0,1}}
// using for loop, iterate over the vector/array
// distance formula = sqrt[(x2-x1)^2 + (y2-y1)^2] => (x2)^2 + (y2)^2
// make maxheap of pair<int,pair<int,int>>
// heapify on distance and thats it

#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;

int main(){
    int k=2;
    vector<vector<int>> input{
        {1,3},
        {-2,2},
        {5,8},
        {0,1}
    };
    priority_queue<pair<int,pair<int,int>>> maxheap;

    for (int i=0;i<input.size();i++){
        int x_cord=input[i][0];
        int y_cord=input[i][1];
        int x_cord2=x_cord*x_cord;
        int y_cord2=y_cord*y_cord;
        int dist=x_cord2+y_cord2;
        maxheap.push(make_pair(dist,make_pair(x_cord,y_cord)));
        if(maxheap.size()>2){
            maxheap.pop();
        }
    }
    while(maxheap.size()>0){
        cout << maxheap.top().second.first << ",";
        cout << maxheap.top().second.second << endl;
        maxheap.pop();
    }
    
    return 0;
}