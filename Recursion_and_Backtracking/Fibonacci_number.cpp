#include <bits/stdc++.h>
using namespace std;

int Fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int last = Fibonacci(n - 1);
    int slast = Fibonacci(n - 2);
    return last + slast;
}

int main()
{
    cout << Fibonacci(4) << endl;
    return 0;
}