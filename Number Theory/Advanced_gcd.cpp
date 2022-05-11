#include <bits/stdc++.h>

using namespace std;
#define ll long long int

ll GCD(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    return GCD(b, a % b);
}
ll reduceTo(ll a, string b)
{
    ll mod = 0;
    for (ll i = 0; b[i] != '\0'; i++)
    {
        mod = (mod * 10 + b[i]) % a;
    }
    return GCD(a, mod);
}

int main()
{
    ll a;
    string b;
    cin >> a >> b;
    if (a == 0)
    {
        cout << b << endl;
        return 0;
    }
    else
    {
        cout << reduceTo(a, b) << endl;
    }
    return 0;
}