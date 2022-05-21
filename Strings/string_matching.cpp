#include <bits/stdc++.h>
using namespace std;
bool matching(string s, string p)
{
    int n = s.length();
    int m = p.length();
    for (int i = 0; i < n - m; i++)
    {
        bool isFound = true;
        for (int j = 0; j < m; j++)
        {
            if (s[i + j] != p[j])
            {
                isFound = false;
                break;
            }
        }
        if (isFound == true)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string s, p;
    cin >> s;
    cin >> p;
    if (matching(s, p) == true)
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
    return 0;
}