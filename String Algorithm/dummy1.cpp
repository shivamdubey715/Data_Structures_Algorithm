#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int k, n;
        cin >> k >> n;
        vector<int> dp(k);
        for(int i=0;i<k;i++){
            int temp=0;
            string s;
            cin >> s;
            for (int j = 0; s[j] != '\0'; j++)
            {
                temp += s[j];
            }
            dp[i] = temp;
        }
        // cout << dp[0]<<" " <<dp[1] <<" "<< dp[2]<<" " <<endl;
        int ans  = INT_MAX;
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j<k; j++)
            {
                if(i==j){
                    continue;
                }
                ans = min(ans, abs(dp[j] - dp[i]));
            }
            cout << dp[i]<<" ";
        }
        cout << endl;
        // cout << ans<<endl<<endl;
    }
    return 0;
}