#include <bits/stdc++.h>
using namespace std;

int solution1(int day, int last, vector<vector<int>> points, vector<vector<int>> dp)
{
    if (dp[day][last] != -1)
    {
        return dp[day][last];
    }
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i <= 2; i++)
        {
            if (i != last)
            {
                maxi = max(maxi, points[0][i]);
            }
        }
        return dp[day][last] = maxi;
    }
    int maxi = 0;
    for (int i = 0; i <= 2; i++)
    {
        if (i != last)
        {
            int activity = points[day][i] + solution1(day - 1, i, points, dp);
            maxi = max(maxi, activity);
        }
    }
    return dp[day][last] = maxi;
}
int solution2(int n, vector<vector<int>> points)
{
    vector<vector<int>> dp(4, vector<int>(4, 0));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            for (int task = 0; task <= 2; task++)
            {
                if (last != task)
                {
                    int activity = points[day][task] + dp[day-1][task];
                    dp[day][last] =  max(dp[day][last], activity);
                }
            }
            
        }
    }
    return dp[n-1][3];
    
}
int main()
{

    vector<vector<int>> points = {{10, 40, 70},
                                  {20, 50, 80},
                                  {30, 60, 90}};

    int n = points.size();
    vector<vector<int>> dp(n, vector<int>(4, -1));
    cout << solution2(n, points) << endl;
    ;
}