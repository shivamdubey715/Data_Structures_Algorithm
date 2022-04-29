#include<bits/stdc++.h>
using namespace std;
int powerOf(int a, int b){
    if(b==0){
        return 1;
    }
    int res = powerOf(a, b/2);
    if(b&1){
        return a*res*res;
    }
    else{
        return res*res;
    }
}

int powerOF(int a, int b){
    int ans=1;
    while(b){
        if(b&1){
            ans = ans*a;
        }
        a=a*a;
        b>>=1;
    }
    return ans;
}
int main(){
    int a,b;
    cin>>a>>b;
    cout <<powerOF(a, b)<<endl;
}