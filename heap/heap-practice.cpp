// 2 https://leetcode.com/problems/kth-largest-element-in-an-array/
// 3 https://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/
// 4 https://www.geeksforgeeks.org/nearly-sorted-algorithm/
// 5 https://leetcode.com/problems/find-k-closest-elements/
// 6 https://leetcode.com/problems/top-k-frequent-elements/
// 7 https://leetcode.com/problems/sort-array-by-increasing-frequency/
// 8 https://leetcode.com/problems/k-closest-points-to-origin/
// 9 https://www.geeksforgeeks.org/connect-n-ropes-minimum-cost/

#include <iostream>

using namespace std;

int fib(int x){
    int f1=0,f2=1,result;
    for(int i=2;i<=x;i++){
        result=f1+f2;
        f1=f2;
        f2=result;
    }
    return result;
}

int main(){
    int input=9;
    int ans = fib(input);
    cout << ans << endl;
    return 0;
}