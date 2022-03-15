/*
Using this algorithm we can find no. of prime numbers between a range
*/

#include <iostream>
using namespace std;

void primeSieve(int n, int x)
{
    int count = 0;
    int prime[x] = {0};
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = 1;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            count++;
            // cout << i <<" ";
        }
    }
    cout << count << endl;
}

int main()
{
    int n;
    cin >> n;
    int x;
    cin >> x;
    primeSieve(n, x);
}