// Method 1:
// Time complexcity: O(n);

// #include "bits/stdc++.h"
// using namespace std;

// void PrintTwoElements(int A[], int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         if (A[abs(A[i]) - 1] > 0)
//         {
//             A[abs(A[i]) - 1] = -A[abs(A[i]) - 1];
//         }
//         else
//         {
//             cout << "Repitting element is: " << endl;
//             cout << abs(A[i]) << endl;
//         }
//     }
//     for (int i = 0; i < size; i++)
//     {
//         if (A[i] > 0)
//         {
//             cout << "Missing elements is: " << endl;
//             cout << i + 1 << endl;
//         }
//     }
// }

// int main()
// {
//     int A[] = {7, 3, 4, 5, 5, 6, 2};
//     int n = sizeof(A) / sizeof(A[0]);
//     PrintTwoElements(A, n);
//     return 0;
// }