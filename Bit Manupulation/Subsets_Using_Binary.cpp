#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[]={3, 2, 4};
    int n=3;
    for (int num = 0; num <= (1<<n)-1; num++)
    {
        vector<int> ds;
        for (int bit = 0; bit <= n-1; bit++)
        {
            if (num & (1<<bit))
            {
                ds.push_back(a[bit]);
            }
        }
        for(auto it: ds){
            cout << it <<" ";
        }
        cout << endl;
    }
    return 0;
}