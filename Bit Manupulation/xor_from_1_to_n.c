
//Method: 1
//Time complexity: O(n^2)
// #include<stdio.h>

// int main(){
//     int res =0, n;
//     scanf("%d", &n);
//     for(int i = 1; i<n;i++){
//         res = res ^ i;
//         printf("%d\n", res);
//     }
//     printf("%d\n", res);
//     return 0;
// }

// Method: 2
//Time complexity: O(n)
//Observe the pattern
#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    if (n%4==0)
    {
        printf("%d\n", n);
    }
    if (n%4==1)
    {
        printf("1\n");
    }
    if (n%4==2)
    {
        printf("%d\n", n+1);
    }
    if (n%4==3)
    {
        printf("0\n");
    }
    
    return 0;
}