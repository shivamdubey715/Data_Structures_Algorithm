

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:

    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> r(numRows);
        for (int i = 0; i < numRows; i++)
        {
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;
            for (int j = 1; j < i; j++)
            {
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
            }
        }
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 1; j < i; j++)
            {
                cout << r[i][j] << " ";
            }
            cout << endl;
            
        }
        
        return r;
    }
};

int main()
{
    Solution ob;
    ob.generate(7);
    return 0;
}