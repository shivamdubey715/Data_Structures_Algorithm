#include <bits/stdc++.h>

using namespace std;
class solution
{
public:
    void findSubsets(int ind, vector<int> nums, vector<int> ds, vector<vector<int>> ans)
    {
        ans.push_back(ds);
        for (int i = ind; i < nums.size(); i++)
        {
            if (i != ind && nums[i] == nums[i - 1])
            {
                continue;
            }
            ds.push_back(nums[i]);
            findSubsets(i + 1, nums, ds, ans);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> subsetWithDup(vector<int> nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        findSubsets(0, nums, ds, ans);
        return ans;
    }
};

int main(){
    solution ob;
    vector<vector<int>> ans = ob.subsetWithDup();
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (int u : ans[i])
        {
            cout << u << " ";
        }
        cout << "]";
    }
    return 0;
}