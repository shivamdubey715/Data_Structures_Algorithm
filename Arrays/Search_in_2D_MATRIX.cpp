#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int lo = 0;
        if (!matrix.size())
            return false;
        int hi = (matrix.size() * matrix[0].size()) - 1;

        while (lo <= hi)
        {
            int mid = (lo + (hi - lo) / 2);
            if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] == target)
            {
                return true;
            }
            if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] < target)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return false;
    }
};
int main()
{
    vector<vector<int>> matrix{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    Solution ob;
    cout << ob.searchMatrix(matrix, 30) << endl;
    return 0;
}