#include <bits/stdc++.h>
using namespace std;

int oneMissing(int *arr)
{
    int size = 4;
    int totalXor = 0;
    int arrXor = 0;
    for (int i = 1; i <= size + 1; i++)
    {
        totalXor ^= i;
    }
    for (int i = 0; i < size; i++)
    {
        arrXor ^= arr[i];
    }
    return totalXor ^ arrXor;
}
int main()
{
    int arr[] = {1, 2, 4, 5};
    cout << oneMissing(arr) << endl;
}