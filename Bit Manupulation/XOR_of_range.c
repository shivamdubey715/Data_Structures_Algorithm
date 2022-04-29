//Condition: Time complexity = O(1)
//This problem can be solved using loop but we can solve it in constant time complexity 
//let's calculate 3^4^5 ------> can be written as (1^2^3^4^5)^(1^2), That's why we can use right^(left-1)
#include<stdio.h>

int main(){
    int left, right;
    scanf("%d", &left);
    scanf("%d", &right);
    printf("%d\n", right^(left-1));
    return 0;
}