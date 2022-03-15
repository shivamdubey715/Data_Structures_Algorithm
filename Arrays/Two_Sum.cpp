
// Brute Force Method:
// Time cimplexity = O(n^3)

// #include "bits/stdc++.h"
// using namespace std;
// bool checkSum(int *A, int n, int target){
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i+1; j < n; j++)
//         {
//             for (int k = j+1; k < n; k++)
//             {
//                 if (A[i] + A[j] + A[k] == target)
//                 {
//                     return true;
//                     break;
//                 }
                
//             }
            
//         }
        
//     }
//         return false;
    
// }
// int main(){
//     int arr[] = {1, 2, 3, 4, 5, 6, 7};
//     int target = 500;
//     cout << checkSum(arr, 7, target) << endl;
//     return 0;
// }

//Optimised solution:
// Time complexity = O(n^2)
#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, target;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    sort(A.begin(),A.end());
    cout << "Enter the target" << endl;
    cin >> target;
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        int lo = i + 1, hi = n - 1;
        while (lo < hi)
        {
            int current = A[i] + A[lo] + A[hi];
            if (current == target)
            {
                found = true;
            }
            else if (current < target)
            {
                lo++;
            }
            else{
                hi++;
            }
        }
    }
    cout << found << endl;
    return 0;
}
    