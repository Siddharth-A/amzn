/* JULY 27 - AUG 3
q1: two-sum:                            https://leetcode.com/problems/two-sum/solution/
q2: best time to buy and sell stock:    https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/
q3: 
q4: 
q5: 
q6: 
q7: 
q8: 

*/
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void twosum(){
    // O(n) optimization using unordered map
    // use vector elems as map key and index as map value so you can easily use map.count() func
    int target=6;
    vector<int> input{2,3,4};

    unordered_map<int, int> umap;
    vector<int> sol;

    for(int i=0; i<input.size(); i++){
        int x = input[i];
        if(umap.count(target-x)){
            sol.push_back(i);
            sol.push_back(umap[target-x]);
        }
        else
            umap.insert({x,i});
    }

    for(auto y:sol)
        cout << y << " ";
    cout << endl;

}

void bestime(){
    vector<int> price{7,1,5,3,6,4};
    // vector<int> price{7,6,4,3,1};
    int maxprofit = 0;
    int minprice = price[0];
    int currprice = 0;

    for(int i=0; i<price.size();i++){
        currprice = price[i];

        if(minprice > currprice)
            minprice = currprice;
        
        if(maxprofit < (currprice-minprice))
            maxprofit = currprice-minprice;
    }
    cout << "max profit: " << maxprofit << endl;
}

int main(){

    // twosum();
    bestime();
    return 0;
}

