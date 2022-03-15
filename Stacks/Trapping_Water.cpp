#include "bits/stdc++.h"
// #include<vector>
using namespace std;

int maxWater(vector<int> arr, int n)
{

    // To store the maximum water
    // that can be stored
    int res = 0;

    // For every element of the array
    for (int i = 1; i < n - 1; i++)
    {

        // Find the maximum element on its left
        int left = arr[i];
        for (int j = 0; j < i; j++)
            left = max(left, arr[j]);

        // Find the maximum element on its right
        int right = arr[i];
        for (int j = i + 1; j < n; j++)
            right = max(right, arr[j]);

        // Update the maximum water
        res = res + (min(left, right) - arr[i]);
    }

    return res;
}

int main()
{
    vector<int> a = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << maxWater(a, a.size()) << endl;
    return 0;
}

// long long int left = 0, right = n - 1, res = 0, maxleft = 0, maxright = 0;
// while (left <= right)
// {
//     if (arr[left] <= arr[right])
//     {
//         if (arr[left] >= maxleft)
//         {
//             maxleft = arr[left];
//         }
//         else
//         {
//             res += maxleft - arr[left];
//         }
//         left++;
//     }
//     else
//     {
//         if (arr[right] >= maxright)
//         {
//             maxright = arr[right];
//         }
//         else
//         {
//             res += maxright - arr[right];
//         }
//         right--;
//     }
// }
// return res;
// }