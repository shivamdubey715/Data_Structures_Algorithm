#include <bits/stdc++.h>
using namespace std;

void printUnsorted(int arr[], int size)
{
    int start, end, max, min, i;
    for (start = 0; start < size; start++)
    {
        if (arr[start] > arr[start + 1])
        {
            break;
        }
    }

    if (start == size)
    {
        cout << "Array is already sorted" << endl;
        return;
    }
    
    for (end = size - 1; end > 0; end--)
    {
        if (arr[end] < arr[end - 1])
        {
            break;
        }
    }
    max = arr[start], min = arr[start];
    for (i = start + 1; i <= end; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    for (i = 0; i < start; i++)
    {
        if (arr[i] > min)
        {
            start = i;
            break;
        }
    }
    for (i = size - 1; i >= end + 1; i--)
    {
        if (arr[i] < max)
        {
            end = i;
            break;
        }
    }
    cout << start <<" " << end << endl;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printUnsorted(arr, arr_size);
    getchar();
    return 0;
}