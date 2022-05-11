#include <bits/stdc++.h>
using namespace std;

class triplet
{
public:
    int x;
    int y;
    int gcd;
};

triplet extendedEuclid(int a, int b)
{
    if (b == 0)
    {
        triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }
    triplet smallAns = extendedEuclid(b, a % b);
    triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a / b) * smallAns.y;
    return ans;
}

int mmI(int A, int m)
{
    int ans = extendedEuclid(A, m).x;
    return (ans % m + m) % m;
}
main()
{
    int a, b, d;
    cin >> a >> b >> d;
    int gcd = __gcd(a, b);

    if (d % gcd)
    {
        cout << 0 << endl;
        return 0;
    }
    if (d == 0)
    {
        cout << 1 << endl;
        return 0;
    }
    a /= gcd;
    b /= gcd;
    d /= gcd;

    int y1 = ((d % a) * mmI(b, a)) % a;
    int firstValue = d / b;

    if (d < y1 * b)
    {
        cout << 0 << endl;
    }
    int n = (firstValue - y1) / a;

    cout << n + 1 << endl;
    return 0;
}