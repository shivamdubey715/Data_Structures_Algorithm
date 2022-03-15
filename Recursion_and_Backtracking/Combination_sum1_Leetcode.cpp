#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
   void findCombination(int i, int target, int arr[], vector<vector<int>> ans, vector<int> ds)
   {
      if (target == 0)
      {
         if (target == 0)
         {
            ans.push_back(ds);
         }
         return;
      }
      if (arr[i] <= target)
      {
         ds.push_back(arr[i]);
         findCombination(i, target - arr[i], arr, ans, ds);
         ds.pop_back();
      }
      findCombination(i + 1, target, arr, ans, ds);
   }

public:
   vector<vector<int>> combinationSum(int candidates[], int target)
   {
      vector<vector<int>> ans;
      vector<int> ds;
      findCombination(0, target, candidates, ans, ds);
      return ans;
   }
};
int main()
{
   int candidates[] = {2, 3, 6, 7};
   int target = 7;
   Solution ob;
   vector<vector<int>> result = ob.combinationSum(candidates, target);
   for (int i = 0; i < result.size(); i++)
   {
      for (int j = 0; j < result[i].size(); j++)
      {

         cout << result[i][j];
         if (j<result[i].size() - 1)
         {
            cout << " ";
         }
         
      }
   }
   cout << endl;
   return 0;
}