#include <bits/stdc++.h>
using namespace std;

// Method 1:
// Time complexity: O(n)
// Space Complexity: O(n)
int solution1(int ind, vector<int> arr, vector<int> dp)
{
    if (dp[ind] != -1)
    {
        return dp[ind];
    }
    if (ind == 0)
    {
        return arr[ind];
    }
    if (ind < 0)
    {
        return 0;
    }
    int pick = arr[ind] + solution1(ind - 2, arr, dp);
    int notpick = 0 + solution1(ind - 1, arr, dp);

    return dp[ind] = max(pick, notpick);
}

// Method 2:
// Time complexity: O(n)
// Space Complexity: O(n)
int solution2(int ind, vector<int>& arr, vector<int>& dp){
    
    dp[0]= arr[0];
    int n = arr.size();
    for(int i=1 ;i<n; i++){
        int pick = arr[i];
        if(i>1)
            pick += dp[i-2];
        int nonPick = 0+ dp[i-1];
        
        dp[i]= max(pick, nonPick);
    }
    
    
    return dp[n-1];
}

// Method 3:
// Time complexity: O(n)
// Space Complexity: O(1)
int solution3(int ind, vector<int> arr, vector<int> dp)
{
    int size = arr.size();
    int prev = arr[0], prev2 = 0, cur;
    for (int i = 1; i < size; i++)
    {
        int pick = arr[i];
        if (i > 1)
        {
            pick += prev2;
        }
        int notpick = 0 + prev;
        cur = max(pick, notpick);
        prev2 = prev;
        prev = cur;
    }
    return prev;
}
int main()
{
    vector<int> arr{2, 1, 4, 9};
    int n = arr.size();
    vector<int> dp(n, -1);
    cout << solution2(n - 1, arr, dp) << endl;
    return 0;
}