#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int count = 0;
        for (int i = 0; i < n-1; i++)
        {
            if (a[i] == a[i + 1])
            {
                count++;
            }
        }
        if (count == n - 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            for (int i = 0; i < n - 1; i++)
            {

                if (a[i] % 2 == a[i + 1] % 2)
                {
                    flag = 1;
                    break;
                }
                else
                {
                    flag = 0;
                }
            }
            if (flag == 0)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}