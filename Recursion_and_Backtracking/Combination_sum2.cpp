#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void findCombination(int ind, int target, vector<int> arr, vector<vector<int>> ans, vector<int> ds)
    {
        if (target == 0)
        {
            for (int i = 0; i < ds.size(); i++)
            {
                cout << ds[i] << " ";
            }
            cout << endl;
            // ans.push_back(ds);
            return;
        }
        for (int i = ind; i < arr.size(); i++)
        {
            if (i != ind && arr[i] == arr[i - 1])
            {
                continue;
            }
            if (arr[i] > target)
            {
                break;
            }
            ds.push_back(arr[i]);
            findCombination(i, target - arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};
int main()
{
    vector<int> candidates = {2, 4, 6, 8};
    int target = 8;
    Solution ob;
    ob.combinationSum(candidates, target);
    return 0;
}