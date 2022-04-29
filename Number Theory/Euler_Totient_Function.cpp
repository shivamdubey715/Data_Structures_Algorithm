#include<bits/stdc++.h>

using namespace std;
// #define int long long
const int N = 1e5+1, MOD = 1e9+7;

//Euler totient funtion is denoted by phi

//Method 1:
////Time complexity: O(nlog(logn))
void phi1(int n){
    int totient[N];
    for (int i = 0; i < N; i++)
    {
        totient[i] = i;
    }
    for(int i=2;i<N;i++){
        if(totient[i]==i){
            for (int j = 2*i; j < N; j+=i)
            {
                totient[j] *= i-1;
                totient[j] /= i;
            }
            totient[i] = i-1;
        }
    }
    cout<<totient[n];
    cout<<endl;
}

//Method 1:
//Time complexity: O(sqrt(n))
void phi2(int n){
    int res = n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            res /= i;
            res *= (i - 1);
            while(n%i==0){
                n /= i;
            }
        }
    }
    if(n>1){
        res /= n;
        res *= (n - 1);
    }
    cout << res<<endl;;
}
int main(){
    phi2(12);
    return 0;
}