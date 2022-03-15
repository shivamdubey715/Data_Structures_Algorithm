/*
Subsequences in an array whose sum of elements is equal to s
*/
#include <bits/stdc++.h>

using namespace std;

void func(int i, vector<int> A, int arr[], int s, int sum, int n)
{
    if (i == n)
    {
        if (s == sum)
        {
            for (int i = 0; i < A.size(); i++)
            {
                cout << A[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    A.push_back(arr[i]);
    s += arr[i];
    func(i + 1, A, arr, s, sum, n);
    s -= arr[i];
    A.pop_back();
    func(i + 1, A, arr, s, sum, n);
}
int main()
{
    int arr[] = {2, 3, 6, 7};
    int n = 4;
    int sum = 7;
    vector<int> A;
    func(0, A, arr, 0, sum, 4);
    return 0;
}