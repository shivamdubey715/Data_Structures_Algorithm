#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {1, 1, 2, 5, 3, 2, 3, 4, 7, 4};
    int Xor = 0;
    for (int i = 0; i < 10; i++)
    {
        Xor = Xor^a[i];
    }
    int right_bit = Xor&~(Xor-1);
    int x = 0, y = 0;
    for (int i = 0; i < 10; i++)
    {
        if (a[i] & right_bit)
        {
            x = x ^ a[i];
        }
        else
        {
            y = y ^ a[i];
        }
    }
    cout << x << endl;
    cout << y << endl;
    return 0;
}