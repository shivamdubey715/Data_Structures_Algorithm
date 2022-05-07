#include <bits/stdc++.h>
using namespace std;

int N = 1000000;
int sieve[1000001];
void createSieve()
{
    for (int i = 2; i <= N; i++)
    {
        sieve[i] = 1;
    }
    for (int i = 2; i * i <= N; i++)
    {
        if (sieve[i] == 1)
        {
            for (int j = i * i; j <= N; j++)
            {
                sieve[j] = 0;
            }
        }
    }
}
vector<int> generatePrimes(int N)
{
    vector<int> ds;
    for (int i = 2; i <= N; i++)
    {
        if (sieve[i] == 1)
        {
            ds.push_back(i);
        }
    }
    return ds;
}

int main()
{
    createSieve();
    int l, r;
    cin >> l >> r;
    // Step 1: generate all primes till sqrt(r);
    vector<int> primes = generatePrimes(sqrt(r));

    // Step 2: Create a dummy array of size r - l + r ans make everyone as 1
    int dummy[r - l + r];
    for (int i = 0; i < r - l + 1; i++)
    {
        dummy[i] = 1;
    }

    // Step 3: for all prime number, mark its multiples as 0
    for (auto pr : primes)
    {
        int firstMultiple = (l / pr) * pr;
        for (int j = max(firstMultiple, pr * pr); j <= r; j += pr)
        {
            dummy[j - l] = 0;
        }
    }

    // Step 4: for all primes
    int count = 0;
    for (int i = l; i <= r; i++)
    {
        if (dummy[i - l] == 1)
        {
            count++;
            // cout << i << " ";
        }
    }
    cout << count << endl;
    return 0;
}
