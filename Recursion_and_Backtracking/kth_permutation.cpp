/*
take an integer n, store it's factorial form numbers in numbers arrays and find it's kth permutation
like, if n = 4 then numbers = [1, 2, 3, 4] 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        int fact = 1;
        vector<int> numbers;
        for (int i = 1; i < n; i++)
        {
            fact = fact * i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        string ans = "";
        k = k - 1;
        while (true)
        {
            ans = ans + to_string(numbers[k / fact]);
            numbers.erase(numbers.begin() + k / fact);
            if (numbers.size() == 0)
            {
                break;
            }

            k = k % fact;
            fact = fact / numbers.size();
        }
        return ans;
    }
};
int main()
{
    Solution ob;
    cout << ob.getPermutation(4, 17) << endl;
    return 0;
}