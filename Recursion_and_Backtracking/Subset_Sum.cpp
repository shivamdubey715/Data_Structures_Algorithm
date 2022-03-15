#include <bits/stdc++.h>

using namespace std;

class solution
{
public:
    void func(int ind, int sum, int arr[], int N, vector<int> &sumSubset)
    {
        if (ind == N)
        {
            sumSubset.push_back(sum);
            return;
        }
        func(ind + 1, sum + arr[ind], arr, N, sumSubset);
        func(ind + 1, sum, arr, N, sumSubset);
    }

public:
    vector<int> subsetSum(int arr[], int N)
    {

        vector<int> sumSubset;
        func(0, 0, arr, N, sumSubset);
        sort(sumSubset.begin(), sumSubset.end());
        for (int i = 0; i < sumSubset.size(); i++)
        {
            cout << sumSubset[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int arr[] = {3, 1, 2};
    int N = 3;
    solution ob;
    ob.subsetSum(arr, N);

    return 0;
}