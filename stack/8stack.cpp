// Max area rectangle in binary matrix: Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
// https://leetcode.com/problems/maximal-rectangle/

// 0 1 1 0
// 1 1 1 1 
// 1 1 1 1
// 1 1 0 0 
// break into 4 histograms and apply MAH on each histogram
// max of MAH answer is max area possible in matrix

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
    int input[4][4] = {0,1,1,0,
                       1,1,1,1,
                       1,1,1,1,
                       1,1,0,0};
}