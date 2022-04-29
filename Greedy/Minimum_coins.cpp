// Greedy algorithm to find minimum number of coins

#include<bits/stdc++.h>
using namespace std;

int main(){
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500};
    int n = 9;
    int v;
    cin>>v;
    vector<int> ans;
    for (int i = n-1; i >= 0; i--)
    {
        while(v>=coins[i]){
            v -= coins[i];
            ans.push_back(coins[i]);
        }
    }
    // for (int i = 0; i < ans.size(); i++)
    // {
        cout<<ans.size()<<endl;
    // }
    
}