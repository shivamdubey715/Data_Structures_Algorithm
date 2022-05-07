/*
We are given an ‘N*M’ matrix. We need to find the maximum path sum from any cell of the first row to any cell of the last row.
At every cell we can move in three directions: to the bottom cell (↓), to the bottom-right cell(↘), or to the bottom-left cell(↙).
*/

#include <bits/stdc++.h>
using namespace std;
int solution1(int i, int j, int m, vector<vector<int>> matrix, vector<vector<int>> dp){
    if(j<0 || j>=m){
        return -1e9;
    }
    if(i==0){
        return matrix[i][j]; 
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int up = matrix[i][j] + solution1(i-1, j, m, matrix, dp);
    int leftDiagonal = matrix[i][j] + solution1(i-1, j-1, m, matrix, dp);
    int rightDiagonal = matrix[i][j] + solution1(i-1, j+1, m, matrix, dp);
    return dp[i][j] = max(up,max(leftDiagonal,rightDiagonal));
}

int solution2(vector<vector<int>> matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    
    // Initializing first row - base condition
    for(int j=0; j<m; j++){
        dp[0][j] = matrix[0][j];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int up = matrix[i][j] + dp[i-1][j];

            int rightDiagonal = matrix[i][j];
            if(j-1>= 0){
                rightDiagonal += dp[i-1][j-1];
            }
            else{
                rightDiagonal += -1e9;
            }
            int leftDiagonal = matrix[i][j];
            if(j+1<m){
                leftDiagonal += dp[i-1][j+1];
            }
            else{
                rightDiagonal += -1e9;
            }
            dp[i][j] = max(up, max(rightDiagonal, leftDiagonal));
        }
    }
    int maxi = INT_MIN;
    
    for(int j=0; j<m;j++){
        maxi = max(maxi,dp[n-1][j]);
    }
    
    return maxi;

}

int getMaxPathSum(vector<vector<int>> matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    int maxi = INT_MIN;
    vector<vector<int>> dp(n, vector<int> (m, -1));
    for(int j=0;j<m;j++){
        int ans = solution1(n-1, j, m, matrix, dp);
        maxi = max(ans, maxi);
    }
    return maxi;
}
int main() {
  vector<vector<int> > matrix{{1,2,10,4},
                              {100,3,2,1},
                              {1,1,20,2},
                              {1,2,2,1}};
  
//   cout<<getMaxPathSum(matrix)<<endl;
  cout<<solution2(matrix)<<endl;
  return 0;
}
