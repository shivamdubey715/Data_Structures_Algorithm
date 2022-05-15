#include <bits/stdc++.h>
using namespace std;

int divisorSubstrings(int num, int k)
{
    int temp = num, count =0;
    string s = "";
    while (num != 0)
    {
        char x = num % 10 + '0';
        s = s + x;
        num /= 10;
    }
    reverse(s.begin(), s.end());
    int size = s.size();
    for (int i = 0; i <=size - k; i++)
    {
        int n = stoi(s.substr(i, k));
        if(n==0){
            continue;
        }
        // cout << n <<endl;
        if (temp %n ==0){
            count++;
        }
    }
    return count;

    // for(int i=0;i<num.size();i++){
    //     int x = num % 10;
    //     a[i] = x;
    //     num /= 10;
    // }
}
int main()
{
    cout << divisorSubstrings(430043, 2) << endl;
    return 0;
}