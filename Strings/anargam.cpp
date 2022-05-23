#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s1[] = "decial";
    char s2[] = "medical";
    // We can also put base condition here that if s1 size != s2 size then they are not anargam
    vector<int> temp(26, 0);
    for (int i = 0; s1[i] != '\0'; i++)
    {
        temp[s1[i] - '0']++;
    }
    bool flag = false;
    for (int i = 0; s2[i] != '\0'; i++)
    {
        temp[s2[i] - '0']--;
        if (temp[s2[i] - '0'] < 0)
        {
            cout << "Strings are not anargam" << endl;
            flag = true;
            break;
        }
    }
    if (flag == false)
    {
        cout << "Strings are anargam" << endl;
    }
    return 0;
}