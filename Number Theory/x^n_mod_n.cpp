#include<bits/stdc++.h>
using namespace std;

int modpow(int x, int n, int m){
    if(n==0){
        return 1%m;
    }
    long long u = modpow(x, n / 2, m);
    u = (u*u) % m;
    if (n%2==1)
    {
        u = (u*x)%m;
    }
    return u;
}
int main(){
    int x, n, m;
    cin >> x >> n >> m;
    cout<<modpow( x,  n,  m)<<endl;
    return 0;
}