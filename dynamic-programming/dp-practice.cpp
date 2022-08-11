/**
 *(I)  0-1 knapsack problem
 *      1 subset problem:           https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
 *      2 equal sum partition       https://leetcode.com/problems/partition-equal-subset-sum/
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

bool subsetsum(int input[], int sum, int n){
    // n is i, sum is j
    bool dp[n+1][sum+1];
    memset(dp,-1,sizeof(dp));

    bool sol=0;
    for(int i=0; i<n+1; i++){
        for(int j=0; j<sum+1; j++){
            if(i==0)
                dp[i][j]=0;
            if(j==0)
                dp[i][j]=1;
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(input[i-1]<=j)
                dp[i][j] = (dp[i-1][j-input[i-1]] || dp[i-1][j]);

            else
                dp[i][j] = dp[i-1][j];
        }
    }

    for(int i=0; i<n+1;i++){
        for(int j=0; j<sum+1;j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
        return dp[n][sum];

    // recursive solution
    // // int sol=-1;
    // //base condition
    // if(n==0 | sum==0){
    //     if(n==0)
    //         cout << "valid sum not found" << endl;
    //     else
    //         cout << "valid sum found" << endl;
    //     return 0;
    // }
    
    // if(input[n-1] <= sum){
    //     return max(input[n-1] + subsetsum(input, sum-input[n-1],n-1), subsetsum(input, sum,n-1));
    // }

    // else
    //     return subsetsum(input, sum,n-1);

}

bool equalsumpartition(vector<int> &input){
    int n = input.size();
    int sum=0;
    for(auto x:input)
        sum = sum+x;
    
    if(sum%2 == 0){
        int sumhalf=sum/2;
        bool dp[n+1][sumhalf+1];
        memset(dp,false,sizeof(dp));

        for(int i=0; i<n+1; i++){
            for(int j=0; j<sumhalf+1; j++){
                if(i==0)
                    dp[i][j] = false;
                if(j==0)
                    dp[i][j] = true;
            }
        }

        for(int i=1; i<n+1; i++){
            for(int j=1; j<sumhalf+1; j++){
                int curr = input[i-1];
                
                if(curr <= j)
                    dp[i][j] = dp[i-1][j-curr] | dp[i-1][j];

                else

                    dp[i][j] = dp[i-1][j];

            }
        }
        return dp[n][sumhalf];
    }
    else
        return false;
}

int main(){

// CONCEPT I: 0-1 basic knapsack
//*********************************************************************************************************************//
    /* 0-1 basic knapsack 
    memset(dp,-1,sizeof(dp));

    vector<int> wt{1,3,4,5};
    vector<int> pr{1,4,5,7};
    int maxw=7;
    int n=wt.size()-1;
    int nn=wt.size();

    int maxp = basicknapsackmemoize(wt,pr,maxw,n);
    int maxp2 = basicknapsacktopdown(wt,pr,maxw,n);
    cout << "max price that can be driven for wt:" << maxw << " is = " << maxp2 << endl;
    */

    /* Q1.1 subset problem: Given a set of int and a sum, determine if there is a subset of the given set with sum equal to given sum
   int input[] = {2,3,7,8,10};
   int sum=12;
   int n = sizeof(input)/sizeof(input[0]);
   bool sol = subsetsum(input,sum,n);
   cout << "sol: " << sol << endl;
   */
   

    /* Q1.2 equal sum partition: Given an arr, find if array can be partitioned into 2 subsets s.t sum of elements in both subsets is equal
   */
    vector<int> input{1,5,11,5};
    int sol = equalsumpartition(input);
    cout << "sol: " << sol << endl;


//*********************************************************************************************************************//


    return 0;
}