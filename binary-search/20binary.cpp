// search in sorted matrix
// https://leetcode.com/problems/search-a-2d-matrix/

//  1   3   5   7
//  10  11  16  20
//  23  30  34  60

#include <iostream>
#include <vector>

using namespace std;

bool binarysearch(vector<int>& input,int target){
    int start=0,end,mid=0;
    bool res;
    end=input.size()-1;
    while(start<=end){
        mid=start+(end-start)/2;
        if(target<input[mid]){
            end=mid-1; 
        }
        else if(target>input[mid]){
            start=mid+1;
        }
        else if(target==input[mid]){
            res=true;
            break;
        }
    }
    if(start>end){
        res=false;
    }
    return res;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    bool result;
    int m=matrix.size();
    if(m==0){
        return false;
    }
    for(int i=0;i<matrix.size();i++){
        int rowsize=matrix[i].size();
        // BS on row if target bigger than last elem of row
        if(target<matrix[i][rowsize-1]){
            result=binarysearch(matrix[i],target);
            if(result)
                break;
        }
        // break if target==last elem of row
        else if(target==matrix[i][rowsize-1]){
            result=true;
            break;
        }
        
        else{
            result=false;
        }
    }
    return result;
}

int main(){

    vector<int> input{2,4,6,8};
    int target=8;
    bool result;
    result = binarysearch(input,target);
    cout << result << endl;
    return 0;
}