#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[] = {10, 10, 10};
    int n = 3,flag=0;
    for (int num = 0; num < (1<<n); num++)
    {
        int sum =0;
        for (int bit = 0; bit < n; bit++)
        {
            if(num & (1<<bit)){
                sum += a[bit];
            }
            else{
                sum -= a[bit];
            }
        }
        if (sum % 360 == 0)
        {
            cout << "YES" << endl;
            flag = 1;
            break;
        }
    }
    if (flag==0)
    {
        cout << "N0" << endl;
    }
    return 0;
}  // Here for each subset: 0 --> multiply by +1 and 1 --> multiply by -1 