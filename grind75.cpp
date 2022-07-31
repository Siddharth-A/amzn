/* JULY 27 - AUG 3
q1: two-sum:                            https://leetcode.com/problems/two-sum/solution/
q2: best time to buy and sell stock:    https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/
q3: insert interval:                    https://leetcode.com/problems/insert-interval/
q4: three-sum:                          https://leetcode.com/problems/3sum/
q5: 
q6: 
q7: 
q8: 

*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

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

        umap.insert({input[i],i});
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

void insertinterval(){
    vector<vector<int>> input { {1,2}, {3,5}, {6,7}, {8,10}, {12,16} };
    vector<int> newinterval {4,8};

    int s1, e1, s2, e2;
    vector<vector<int>> sol;

    s2 = newinterval[0];
    e2 = newinterval[1];

    if(input.size()==0){
        sol.push_back({newinterval[0], newinterval[1]});
        return;
    }
    
    for(int i=0; i<input.size();i++){
        s1 = input[i][0];
        e1 = input[i][1];

        // get start2,end2 from sol
        if(sol.size()>0){
            vector<int> temp = sol.back();
            s2 = temp[0];
            e2 = temp[1];
            sol.pop_back();
        }

        // if newint overlaps
        if(e2 >= s1 & s2 <= e1)
            sol.push_back({min(s1,s2), max(e1,e2)});
        

        // if newint does not overlap
        else if(s2 > s1){
            sol.push_back(input[i]);
            sol.push_back({s2,e2});
        }
        else{
            sol.push_back({s2,e2});
            sol.push_back(input[i]);
        }
    }
}

void threesum(){
    //would consider this cheating
    //using set instead to limit the output to only unique cases rather than algorithm
    vector<int> input{-1,0,1,2,-1,-4};
    vector<vector<int>> sol;
    set<vector<int>> solset;

    for(int i=0;i<input.size();i++){
        
        if(int i=0 || input[i] != input[i-1]){
            int j=i+1;
            int k=input.size()-1;
            
            while(j<k){
                
                int target = input[i]+input[j]+input[k];

                if(target==0){
                    solset.insert({input[i],input[j],input[k]});
                    j++;
                    k--;
                    if(input[j]==input[j-1])
                        j++;
                    if(input[k]==input[k+1])
                        k--;
                }

                else if(target>0)
                    k--;
                
                else
                    j++;            
            }

        }
    }
    for (auto it = solset.begin();it != solset.end();it++) {
        sol.push_back(*it);
    }

    cout << sol.size() << endl;

    for(int l=0;l<sol.size();l++){
        for(auto x:sol[l])
            cout << x << " ";
    }

}

int main(){

    // twosum();
    // bestime();
    // insertinterval();
    threesum();
    return 0;
}

