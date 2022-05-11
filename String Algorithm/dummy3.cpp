#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> dp;
        int temp = 0;
        string s;
        cin >> s;
        for (int j = 0; s[j] != '\0'; j++)
        {
            temp += s[j];
        }
        // dp[i] = temp;
        cout <<temp<<endl;
    return 0;
}