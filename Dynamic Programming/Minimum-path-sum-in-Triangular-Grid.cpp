/*
We are given a Triangular matrix. We need to find the minimum path sum from the first row to the last row.
At every cell we can move in only two directions: either to the bottom cell (↓) or to the bottom-right cell(↘)
*/

#include <bits/stdc++.h>
using namespace std;

// Method 1: Recursion
// Time Complexity: O(M*N)
// Space Complexity: O(N) + O(N*N)
int solution1(int i, int j, vector<vector<int>> triangle, int n)
{
    if (i == n - 1)
    {
        return triangle[i][j];
    }
    int down = triangle[i][j] + solution1(i + 1, j, triangle, n);
    int diagonaly = triangle[i][j] + solution1(i + 1, j + 1, triangle, n);
    return min(down, diagonaly);
}

// Method 2: Recursion
// Time Complexity: O(M*N)
// Space Complexity: O(N) + O(N*N)
int solution2(int i, int j, vector<vector<int>> triangle, int n, vector<vector<int>> dp)
{
    if (i == n - 1)
    {
        return triangle[i][j];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int down = triangle[i][j] + solution1(i + 1, j, triangle, n);
    int diagonaly = triangle[i][j] + solution1(i + 1, j + 1, triangle, n);
    return dp[i][j] = min(down, diagonaly);
}

// Method 3: Tabulation
// Time Complexity: O(M*N)
// Space Complexity: O(N*N)
int solution3(int n, vector<vector<int>> triangle)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        dp[n - 1][i] = triangle[n - 1][i];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int up = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(up, diagonal);
        }
    }
    return dp[0][0];
}
// Method 3: Tabulation
// Time Complexity: O(M*N)
// Space Complexity: O(N*N)
int solution4(int n, vector<vector<int>> triangle)
{
    vector<int> front(n, 0), cur(n, 0);
    for (int i = 0; i < n; i++)
    {
        front[i] = triangle[n - 1][i];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int up = triangle[i][j] + front[j];
            int diagonal = triangle[i][j] + front[j + 1];
            cur[j] = min(up, diagonal);
        }
        front = cur;
    }
    return front[0];
}
int main()
{

    vector<vector<int>> triangle{{1},
                                 {2, 3},
                                 {3, 6, 7},
                                 {8, 9, 6, 10}};

    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    //   cout<<solution1(0, 0, triangle,n)<<endl;
    //    cout<<solution2(0, 0, triangle,n, dp)<<endl;
    // cout << solution3(n, triangle) << endl;
    cout << solution4(n, triangle) << endl;
    return 0;
}