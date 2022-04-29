#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k;
  cin>>n>>k;
  vector<string> s(n);
  for(int i=0;i<n;i++) cin>>s[i];
  int ans=0;
  for(int i=0;i<(1<<n);i++){
    vector<int> sum(26);
    for(int j=0;j<n;j++){
      if((i>>j)&1){
        for(int x=0;x<s[j].size();x++){
            sum[s[j][x]-'a']++;
            cout<<sum[0]<<endl;
        }
      }
    }
    int now=0;
    for(int j=0;j<26;j++) if(sum[j]==k) now++;
    ans=max(ans,now);
  }
  cout<<ans<<endl;
}
