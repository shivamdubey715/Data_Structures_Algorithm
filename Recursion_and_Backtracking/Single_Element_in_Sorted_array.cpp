#include <bits/stdc++.h>

using namespace std;

int singleNonDuplicate(vector<int> A)
{
    int low = 0, high = A.size() - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (A[mid] == A[mid ^ 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return A[low];
}
int main(){
    vector<int> A = {1, 1, 2, 2, 3, 3, 4, 4, 8, 8, 9};
    cout << singleNonDuplicate(A) << endl;
    return 0;
}