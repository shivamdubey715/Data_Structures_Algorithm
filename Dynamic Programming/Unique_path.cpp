/* 
Given two values M and N, which represent a matrix[M][N]. We need to find the total unique paths from the top-left cell (matrix[0][0]) to the rightmost cell (matrix[M-1][N-1]).
At any cell we are allowed to move in only two directions:- bottom and right.
*/

#include <bits/stdc++.h>
using namespace std;
int m, n;

// Method 1: Recursion
// Time Complexity: O(M*N)
// Space Complexity: O((N-1)+(M-1)) + O(M*N)
int solution1(int i, int j){
    if (i==0&&j==0)
    {
        return 1;
    }
    if (i < 0 || j < 0)
    {
        return 0;
    }
    int up = solution1(i-1,j);
    int left = solution1(i, j-1);
    return up + left;
}

// Method 2: Memoization of Recursion
// Time Complexity: O(M*N)
// Space Complexity: O((N-1)+(M-1)) + O(M*N)
int solution2(int i, int j){
    vector<vector<int>> dp(m, vector<int> (n, -1));
    if (i==0&&j==0)
    {
        return 1;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if (i < 0 || j < 0)
    {
        return 0;
    }
    int up = solution1(i-1,j);
    int left = solution1(i, j-1);
    return dp[i][j] = up + left;
}
// Method 3: Tabulation
// Time complexity: O(m*n)
// Space Complexity: O(m*n)
int solution3(){
    vector<vector<int>> dp(m, vector<int> (n, -1));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0){
                dp[i][j] = 1;
                continue;
            }
            int up=0;
            int left = 0;
            if(i>0){
                up = dp[i-1][j];
            }
            if(j>0){
                left = dp[i][j-1];
            }
            dp[i][j] = up+left;
        }
    }
    return dp[m-1][n-1];
}
int main() {

  m=3;
  n=2;
//   cout<<solution3()<<endl;
printf("1/2 = %f", (float)(1/2));
  return 0;
}