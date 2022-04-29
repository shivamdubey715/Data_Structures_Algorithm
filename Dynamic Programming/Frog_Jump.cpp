#include <bits/stdc++.h>
using namespace std;


// Method 1:
//Time complexity: O(n)
// Space Complexity: O(n)
int solution1(int ind, vector<int> height, vector<int> dp)
{
    if (ind == 0)
    {
        return 0;
    }
    if (dp[ind] != -1)
    {
        return dp[ind];
    }
    int jumpTwo = INT_MAX;
    int jumpOne = solution1(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);
    if (ind > 1)
    {
        jumpTwo = solution1(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);
    }
    return dp[ind] = min(jumpOne, jumpTwo);
}

// Method 2:
// Time complexity: O(n)
// Space Complexity: O(n)
int solution2(int ind, vector<int> height, vector<int> dp)
{
    int n = height.size();
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int jumpTwo = INT_MAX;

        int jumpOne = dp[i - 1] + abs(height[i] - height[i - 1]);
        if (ind > 1)
        {
            jumpTwo = dp[i - 2] + abs(height[i] - height[i - 2]);
        }
        dp[i] = min(jumpOne, jumpTwo);
    }
    return dp[n - 1];
}

// Method 2:
// Time complexity: O(n)
// Space Complexity: O(1)
int solution3(int ind, vector<int> height, vector<int> dp)
{
    // Not using dp
    int n = height.size();
    dp[0] = 0;
    int prev = 0;
    int prev2 = 0;
    int cur;
    for (int i = 1; i < n; i++)
    {
        int jumpTwo = INT_MAX;

        int jumpOne = prev + abs(height[i] - height[i - 1]);
        if (ind > 1)
        {
            jumpTwo = prev2 + abs(height[i] - height[i - 2]);
        }
        cur = min(jumpOne, jumpTwo);
        prev2 = prev;
        prev = cur;
    }
    return prev;
}
int main()
{

    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    vector<int> dp(n, -1);
    cout << solution3(n - 1, height, dp) << endl;
    return 0;
}