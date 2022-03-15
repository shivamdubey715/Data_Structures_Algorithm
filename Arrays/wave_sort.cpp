#include "bits/stdc++.h"
using namespace std;

void waveSort(int A[], int n)
{
    for (int i = 1; i < n - 1;)
    {
        if (A[i] > A[i - 1])
        {
            swap(A[i], A[i - 1]);
        }
        if (A[i] > A[i + 1] && i <= n - 2)
        {
            swap(A[i], A[i + 1]);
        }
        i += 2;
    }
}
int main()
{
    int A[] = {1, 3, 4, 7, 5, 6, 2};
    waveSort(A, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}