#include <bits/stdc++.h>

using namespace std;

void Subsequence(int ind, vector<int> A, int arr[], int n)
{
    
    if (ind == n)
    {
        for (int i = 0; i < A.size(); i++)
        {
            
            cout << A[i] << " ";
        }
        cout << endl;
        return;
    }
    // take or pick the particular index into the subsequence
    A.push_back(arr[ind]);
    Subsequence(ind + 1, A, arr, n);
    A.pop_back();

    Subsequence(ind + 1, A, arr, n);
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = 3;
    vector<int> A;
    Subsequence(0, A, arr, n);
    return 0;
}
// Time complexity = 2^n;
// Space complexity = O(n);