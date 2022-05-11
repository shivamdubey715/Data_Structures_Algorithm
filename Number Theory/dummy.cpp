#include <bits/stdc++.h>
using namespace std;

string largestGoodInteger(string num) {
        // vector<int> dp;
        int count =INT_MIN, ans =INT_MIN, x, y, flag = 0;
        int n =num.size();
        for(int i=0;i<n-2;i++){
            if(num[i] == num[i+1] && num[i] == num[i+2]){
                count = (num[i] - '0')*100 + (num[i+1] - '0')*10 +(num[i+2] - '0');
                flag =1;
                // cout << count <<endl;
            }
            if(count > ans){
                ans  = count;
                x = i;
                cout<<x<<endl;
                y=i+2;
                cout << y<<endl;
            }
        }
        // string t;
        // for(int i=x;i<y;i++){
        //     t[i] = num[i];
        // }
        // if(flag==0){
        //     return "";
        // }
        // else{
        //     return t;
        // }
        return num.substr(x, 3);
    }
int main()
{
    string s;
    cin >> s;
    cout<<largestGoodInteger(s)<<endl;
    return 0;
}