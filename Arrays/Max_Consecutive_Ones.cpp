#include <bits/stdc++.h>
using namespace std;

int maxConsecutiveOnes(vector<int> A, int k, int n){
    int ZeroCount = 0, i = 0, ans = 0;
    for (int j = 0; j < n; j++)
    {
        if (A[j] == 0)
        {
            ZeroCount++;
        }
        while (ZeroCount > k)
        {
            if (A[i] == 0)
            {
                ZeroCount--;
            }
            i++;
        }
        ans = max(ans, j - i + 1);
    }
    return ans;
}
int main(){
    int n, k;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    cout << "Enter the value of k" << endl;
    cin >> k;
    cout << maxConsecutiveOnes(A, k, n) << endl;
    return 0;
}