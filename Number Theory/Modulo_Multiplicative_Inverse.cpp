/*
mmi = modulo multipliacte inverse
eea = extended euclid's algorithm

mmi ---> find B such that (A.B) % m = 1 where A and m are given

Derivation:
(A.B) % m = 1
(A.B - 1) % m = 0
(A.B - 1) = mq
(A.B) - mq = 1
(A.B) + m(-q) = 1
(A.B) + mQ = 1   ..... It is of form ax + by = c (eea) wherer c is gcd(a, b)
so, comparing both equations B = x
so we need to calculate B(=x) using eeu but for that contion is:
gcd(A, m) = 1
*/

#include <bits/stdc++.h>
using namespace std;

class triplet
{
    public:
        int x;
        int y;
        int gcd;
};

triplet extendedEuclid(int a, int b){
    if(b==0){
        triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }
    triplet smallAns = extendedEuclid(b, a%b);
    triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a/b)*smallAns.y;
    return ans;
}

triplet mmI(int A, int m){
    triplet ans = extendedEuclid(A, m);
    return ans;
}
main()
{
    int a;
    int b;
    cin >> a >> b;
    triplet ans = mmI(a, b);
    cout << ans.x <<endl;
    return 0;
}
