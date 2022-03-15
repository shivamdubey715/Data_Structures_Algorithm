// We use extended method of Moore's voting algorithm here.

#include <bits/stdc++.h>
using namespace std;

void majorityElement(vector<int> arr)
{
    int number1 = -1, number2 = -1, count1 = 0, count2 = 0;
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == number1)
        {
            count1++;
        }
        else if (arr[i] == number2)
        {
            count2++;
        }
        else if (count1 == 0)
        {
            number1 = arr[i];
            count1++;
        }
        else if (count2 == 0)
        {
            number2 = arr[i];
            count2++;
        }
        else
        {
            count1--, count2--;
        }
    }
    vector<int> ans;
    count1 = count2 = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == number1)
        {
            count1++;
        }
        else if (arr[i] == number2)
        {
            count2++;
        }
    }
    if (count1 > size / 3)
    {
        ans.push_back(number1);
    }
    if (count2 > size / 3)
    {
        ans.push_back(number2);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> arr = {1, 1, 1, 3, 3, 2, 2, 2};
    majorityElement(arr);
    return 0;
}