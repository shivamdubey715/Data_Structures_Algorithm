#include <bits/stdc++.h>

using namespace std;

void reverse(int i, string s)
{
    static int k = 0;
    if (i == s.length())
    {
        return;
    }
    reverse(i + 1, s);
    if (k <= i)
    {
        swap(s[k++], s[i]);
       
    }
}

int main()
{
    string s = "binod";
    reverse(0, s);
    cout << s << endl;
    return 0;
}

