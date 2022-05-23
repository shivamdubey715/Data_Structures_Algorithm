#include<bits/stdc++.h>
using namespace std;
#define int long long

int lis(vector<int> arr, int n)
{
    int lis[n];
 
    lis[0] = 1;
    for (int i = 1; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }
 
    // Return maximum value in lis[]
    return *max_element(lis, lis + n);
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        vector<int> temp = a;
        reverse(temp.begin(), temp.end());
        cout << min(lis(a, n), lis(temp, n))<<endl;
    }
    return 0;
}