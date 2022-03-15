/*
Subarray:
Contininuous part of the array.
Number of subarrays of an array with n elements = n*(n + 1)/2.

example:
      {1, 2, 3, 4}
      subarrays = {1} {1, 2} {1, 2, 3} {1, 2, 3, 4}
                  {2} {2, 3} {2, 3, 4}
                  {3} {3, 4}
                  {4}
*/

// Question: Sum of each subarray:
// #include "bits/stdc++.h"

// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     int a[n];
//     int subarrays = n * (n + 1) / 2;
//     cout << "Total number of subarrays possible: " << subarrays << endl;
//     cout << "Enter the elements of array:" << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     cout << "Sum of subarrays" << endl;
// int curr = 0;
// for (int i = 0; i < n; i++)
// {
//     curr = 0;
//     for (int j = i; j < n; j++)
//     {
//         curr += a[j];
//         cout << curr << endl;
//     }
// }
//     return 0;
// }

/*
                   Maximum subarray(means the cintiguous subarray whose sum of element is maximum)
*/

//  Method 1: Divide and Conquer method(O(n))
// #include "bits/stdc++.h"
// #include "limits.h"
// #include "math.h"
// using namespace std;

// int Find_Max_Crossing_Subarray(int *A, int low, int mid, int high)
// {
//     int left_sum = INT_MIN;
//     int sum = 0, max_left;
//     for (int i = mid; i >= low; i--)
//     {
//         sum = sum + A[i];
//         if (sum > left_sum)
//         {
//             left_sum = sum;
//             max_left = i;
//         }
//     }
//     int right_sum = INT_MIN, max_right;
//     sum = 0;
//     for (int j = mid + 1; j <= high; j++)
//     {
//         sum = sum + A[j];
//         if (sum > right_sum)
//         {
//             right_sum = sum;
//             max_right = j;
//         }
//     }
//     return (max_left, max_right, left_sum + right_sum);
// }
// int maxSubArraySum(int arr[], int l, int h)
// {
    // Base Case: Only one element
    // if (l == h)
    //     return arr[l];

//     // Find middle point
//     int m = (l + h) / 2;

//     /* Return maximum of following three possible cases
//             a) Maximum subarray sum in left half
//             b) Maximum subarray sum in right half
//             c) Maximum subarray sum such that the subarray
//        crosses the midpoint */
//     return max(maxSubArraySum(arr, l, m),
//                maxSubArraySum(arr, m + 1, h),
//                Find_Max_Crossing_Subarray(arr, l, m, h));
// }
// int main()
// {
//     int n;
//     cin >> n;
//     int a[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     int result = maxSubArraySum(a, 0, n - 1);
//     cout << result << endl;
//     return 0;
// }

// Method 2: Cumulutive sum approach(O(n^2))
// #include "bits/stdc++.h"
// #include "math.h"
// using namespace std;

// int main(){
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     int currsum[n + 1];
//     currsum[0] = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         currsum[i] = currsum[i - 1] + arr[i - 1];
//     }
//     int maxSum = INT_MIN;
//     for (int i = 1; i <= n; i++)
//     {
//         int sum = 0;
//         for (int j = 0; j < i; j++)
//         {
//             sum = currsum[i] - currsum[j];
//             maxSum = max(sum, maxSum);
//         }

//     }
//     cout << maxSum << endl;

// }

// Method 3: Kadane's algorithm(best approach O(n))

// #include "bits/stdc++.h "
// #include "math.h"
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     int currentSum = 0;
//     int maxSum = INT_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         currentSum += arr[i];
//         if (currentSum < 0)
//         {
//             currentSum = 0;    // If number is negative assign it's value to 0
//         }
//         maxSum = max(maxSum, currentSum);
//     }
//     cout << maxSum << endl;
// }

// Question: Find the contiguous subarray whose is equal to a variable x?

#include "bits/stdc++.h"
#include "math.h"
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int i = 0, j = 0, start = -1, end = -1, sum = 0, s;
    cout << "Enter the value of s" << endl;
    cin >> s;
    while (j < n && sum + arr[j] <= s)
    {
        sum += arr[j];
        j++;
    }
    if (sum == s)
    {
        cout << i + 1 << " " << j << endl;
        return 0;
    }
    while (j < n)
    {
        sum += arr[j];
        while (sum > s)
        {
            sum -= arr[i];
            i++;
        }
        if (sum == s)
        {
            start = i + 1;
            end = j + 1;
            break;
        }
        j++;
    }
    cout << start << " " << end << endl;
}

/* Maximum Circular Subarray Sum */
// #include "bits/stdc++.h"
// #include "math.h"
// using namespace std;
/*
 let an array {4, -4, 6, -6, 10, -11, 12}
 Here maximum circular array is {12, 4, -4, 6, -6, 10}
 Logic:
 WE will remove all the non contributing elements from the array.
 This can be done by reversing the sign of each element element in the array and then apply the kadane's rule.
 so array will be after reversing sign = {-4, 4, -6, -10, 11, -12} now appling kadane's rule we will get 11 as non contributing element.
 Max circular array = TOtal sum ofarray - Sum of non contributing elements
 */
// int kadane(int *arr, int n)
// {
//     int currentSum = 0;
//     int maxSum = INT_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         currentSum += arr[i];
//         if (currentSum < 0)
//         {
//             currentSum = 0; // If number is negative assign it's value to 0
//         }
//         maxSum = max(maxSum, currentSum);
//     }
//     return maxSum;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n], sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//         sum += arr[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         arr[i] = -arr[i];
//     }

//     // cout << maxSum << endl;
//     cout << sum + kadane(arr, n) << endl;
// }