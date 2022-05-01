/*
We are given an “N*M” Maze. The maze contains some obstacles. A cell is ‘blockage’ in the maze if its value is -1. 0 represents non-blockage. There is no path possible through a blocked cell.
We need to count the total number of unique paths from the top-left corner of the maze to the bottom-right corner. At every cell, we can move either down or towards the right.
*/

#include <bits/stdc++.h>
using namespace std;
int n, m;


// Method 1: Recursion
// Time Complexity: O(M*N)
// Space Complexity: O((N-1)+(M-1)) + O(M*N)
int Solution1(int i, int j, vector<vector<int>> maze)
{
    if (i > 0 && j > 0 && maze[i][j] == -1)
    {
        return 0;
    }
    if (i == 0 && j == 0)
    {
        return 1;
    }
    if (i < 0 || j < 0)
    {
        return 0;
    }
    int up = Solution1(i - 1, j, maze);
    int left = Solution1(i, j - 1, maze);
    return up + left;
}

// Method 2: Tabulation
// Time Complexity: O(M*N)
// Space Complexity: O(M*N)
int Solution2(vector<vector<int>> maze, vector<vector<int>> dp)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i > 0 && j > 0 && maze[i][j] == -1)
            {
                dp[i][j] = 0;
                continue;
            }
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }
            int up = 0;
            int left = 0;
            if (i > 0)
            {
                up = dp[i - 1][j];
            }
            if (j > 0)
            {
                left = dp[i][j - 1];
            }
            dp[i][j] = up + left;
        }
    }
    return dp[n - 1][m - 1];
}
// Method 2: Tabulation
// Time Complexity: O(M*N)
// Space Complexity: O(N)
int Solution3(vector<vector<int>> maze)
{
    vector<int> prev(m, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i > 0 && j > 0 && maze[i][j] == -1)
            {
                temp[j] = 0;
                continue;
            }
            if (i == 0 && j == 0)
            {
                temp[j] = 1;
                continue;
            }
            int up = 0;
            int left = 0;
            if (i > 0)
            {
                up = prev[j];
            }
            if (j > 0)
            {
                left = temp[j - 1];
                ;
            }
            temp[j] = up + left;
        }
        prev = temp;
    }
    return prev[n - 1];
}



int minimumAverageDifference(vector<int> &nums)
    {
        int n = nums.size(), sum = 0, sum2 = 0, maxi = 0, ans = INT_MIN, temp=0;
        vector<int> dp;
        for (int i = 0; i < n; i++)
        {
            sum = sum + nums[i];
            dp[i] = sum;
        }
        for (int i = 0; i < n; i++)
        {
            if(i = n-1){
                maxi = sum / n;
            }
            else {
                maxi = abs((dp[i]/(i+1)) - (dp[n-i-1]/(n-i-1)));
            }
            if(ans < maxi){
                ans = maxi;
                temp = i;
            }
        }
        return temp;
    }
int main()
{
    vector<vector<int>> maze{{0, 0, 0},
                             {0, -1, 0},
                             {0, 0, 0}};

    n = maze.size();
    m = maze[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    // cout << Solution1(n - 1, m - 1, maze) << endl;
    // cout << Solution2(maze, dp) << endl;
    // cout << Solution3(maze) << endl;
    vector<int> nums{2, 5, 3, 9, 5, 3};
    cout<<minimumAverageDifference(nums)<<endl;
    return 0;
}
