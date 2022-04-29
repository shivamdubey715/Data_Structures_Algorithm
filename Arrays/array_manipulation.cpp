#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
long long int ar[N];
int n, m;

void solution1(int a, int b, int d)
{
    long long ans = -1;
    for (int i = a; i <= b; ++i)
    {
        ar[i] += d;
        ans = max(ans, ar[i]);
    }
    cout << ans << endl;
}
void solution2(int a, int b, int d){
    ar[a] += d;
    ar[b+1] -= d;
    long long ans = -1;
    for (int i = 1; i <=n; i++)
    {
        ar[i] += ar[i-1];
    }
    for (int i = 1; i <= n; i++)
    {
        if (ans < ar[i])
        {
            ans = ar[i];
        }
        
    }
    
    cout<<ans<<endl;
}
int main()
{
    cin >> n >> m;
    while (m--)
    {
        int a, b, d;
        cin >> a >> b >> d;
        solution2(a, b, d);
    }
    
    return 0;
}