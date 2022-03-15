#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> num, int target)
{
    vector<vector<int>> res;
    if (num.empty())
    {
        return res;
    }
    int n = num.size();
    sort(num.begin(), num.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int target2 = target - num[j] - num[i];
            int front = j + 1;
            int back = n - 1;
            while (front < back)
            {
                int two_sum = num[front] + num[back];
                if (two_sum < target2)
                {
                    front++;
                }
                else if (two_sum > target2)
                {
                    back--;
                }
                else
                {
                    vector<int> quadruplet(4, 0);
                    quadruplet[0] = num[i];
                    quadruplet[1] = num[j];
                    quadruplet[2] = num[front];
                    quadruplet[3] = num[back];
                    res.push_back(quadruplet);
                    while (front < back && num[front] == quadruplet[2])
                    {
                        front++;
                    }
                    while (front < back && num[back] == quadruplet[3])
                    {
                        back--;
                    }
                }
                while (j + 1 < n && num[j + 1] == num[j])
                {
                    j++;
                }
            }
        }
    }
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return res;
}

int main()
{
    vector<int> arr = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    fourSum(arr, 9);
    return 0;
}