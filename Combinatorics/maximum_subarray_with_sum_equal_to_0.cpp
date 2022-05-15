// We have to find maximum length of subarray whose sum of element is 0

#include<bits/stdc++.h>
using namespace std;

int MxSub(int a[], int n){
    map<int, int> mp;
    int sum =0, len = 0;
    for(int i=0;i<n;i++){
        sum += a[i];
        if(sum==0){
            len = i+1;
        }
        else{
            if(mp.find(sum) !=  mp.end()){
                len = max(len, i - mp[sum]);
            }
            else{
                mp[sum] = i;
            }
        }
    }
    return len;
}

int main(){
    int a[] = {1, -1, 3, 2, -2, -8, 1, 7, 10, 23};
    int n = 10; // Size of array
    cout << MxSub(a, n) <<endl;
    return 0;
}