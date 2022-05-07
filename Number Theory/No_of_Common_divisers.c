#include<stdio.h>
#include <math.h>

int divisible(int n, int a, int b){
    int c1 = n / a;
    int c2 = n / b;
    int c3 = n / (a*b);
    return c1 + c2 - c3;
}

int main()
{
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    printf("%d\n", divisible(n, a, b));
    return 0;
}
