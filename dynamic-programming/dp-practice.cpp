/**
 *(I)  0-1 knapsack problem
 *      1 subset problem
 *      2 equal sum partition
 *      3 count of subset sum
 *      4 minimum subset sum diff
 *      5 target sum
 *      6 # of subset & given diff
 * 
 *(II)  unbounded knapsack problem
 * 
 */

#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string> 

using namespace std;


int dp[100][100];

int basicknapsackmemoize(vector<int> wt, vector<int> pr, int maxw, int n){
    // base condition
    if(n==0 | maxw==0)
        return 0;

    if(dp[n][maxw]!= -1)
        return dp[n][maxw];

    if(wt[n] <= maxw){
        return (dp[n][maxw] = max((pr[n] + basicknapsackmemoize(wt,pr,maxw-wt[n],n-1)), basicknapsackmemoize(wt,pr,maxw,n-1)));
    }

    else if(wt[n] > maxw){
        return (dp[n][maxw] = basicknapsackmemoize(wt,pr,maxw,n-1));
    }
}

int basicknapsacktopdown(vector<int> wt, vector<int> pr, int maxw, int nn){
    int result=-1;
    // base condition
    for(int i=0; i<nn+1; i++){
        for(int j=0; j<maxw+1;j++){
            if(i==0 | j==0)
                dp[i][j]=0;
        }
    }

    for(int i=1; i<nn+1; i++){
        for(int j=1; j<maxw+1;j++){
            if(wt[i-1] <= j)
                dp[i][j] = max( (pr[i-1]+dp[i-1][j-wt[i-1]]) , (dp[i-1][j]) );

            else
                dp[i][j] = dp[i-1][j];

            result = dp[i][j];
        }
    }
    return result;
}

int main(){

// CONCEPT I:0-1 basic knapsack
//*********************************************************************************************************************//
    // 0-1 basic knapsack 
    memset(dp,-1,sizeof(dp));

    vector<int> wt{1,3,4,5};
    vector<int> pr{1,4,5,7};
    int maxw=7;
    int n=wt.size()-1;
    int nn=wt.size();

    int maxp = basicknapsackmemoize(wt,pr,maxw,n);
    int maxp2 = basicknapsacktopdown(wt,pr,maxw,n);
    cout << "max price that can be driven for wt:" << maxw << " is = " << maxp2 << endl;
//*********************************************************************************************************************//

/* Q1.1:
subset problem: given key value pair, find the combination of keys which will give max profit
item wt[] w1 w2 w3 w4
item pr[] p1 p2 p3 p4
max capacity=> w 
*/


    return 0;
}