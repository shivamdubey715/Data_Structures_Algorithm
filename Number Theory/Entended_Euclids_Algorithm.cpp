/*
Find x and y such that ax + by = gcd(a, b);
a and b will be given
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
    cout<<ans.x<<" "<<ans.y<<endl;
    return ans;
}
main()
{
    int a;
    int b;
    cin >> a >> b;
    triplet ans = extendedEuclid(a, b);
    cout<<ans.x<<endl;
    cout<<ans.y<<endl;
    cout<<ans.gcd<<endl;
    return 0;
}