/* 
Given a number of stairs. Starting from the 0th stair we need to climb to the “Nth” stair. At a time we can climb either one or two steps. We need to return the total number of distinct ways to reach from 0th to Nth stair.
*/

#include<bits/stdc++.h>
using namespace std;

int solution1(vector<int> dp, int n){
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int solution2(int n){
    int prev = 1;
    int prev2 = 1;
    for (int i = 2; i <= n; i++)
    {
        int cur = prev + prev2;
        prev2 = prev;
        prev = cur;
    }
    return prev;
}
int main(){
    int n = 3;
    vector<int> dp(n+1, -1);
    dp[0] = 1;
    dp[1] = 1;
    
    cout<<solution2(n)<<endl;
    return 0;
}