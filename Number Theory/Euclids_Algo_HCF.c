#include <stdio.h>

int HCF(int a, int b)
{
    while (b != 0)
    {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}
int GCD(int a, int b){
    if(b==0){
        return a;
    }
    GCD(b, a%b);
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", GCD(a, b));
}