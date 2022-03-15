                                              /* Calculate the prime factors of given numbers */                                

#include <iostream>

using namespace std;

void primefactor(int n)
{
    int spf[1000] = {0};   // spf -> Smallest prime factor's
    for (int i = 2; i <= n; i++)
    {
        spf[i] = i;
    }

    for (int i = 2; i <= n; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= n; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
    cout << spf[i] << " ";
    }
    // while (n != 1)
    // {
    //     cout << spf[n] << " ";
    //     n = n / spf[n];
    // }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    primefactor(n);
    return 0;
}