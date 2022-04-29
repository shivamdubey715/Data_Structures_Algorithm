#include <bits/stdc++.h>
using namespace std;

void twoMissing(int* arr, int size){
    int size2 = size+2;
    long totalSum = size2 * ( size2 - 1)/2;
    long arrSum = 0;
    for (int i = 0; i < size; i++)
    {
        arrSum += arr[i];
    }
    int pivot = (totalSum - arrSum)/2;
    int totalLeftXor = 0;
    int arrLeftXor = 0;
    int totalRightXor = 0;
    int arrRightXor = 0;
    for(int i = 1;i<=pivot;i++){
        totalLeftXor ^= i;
    }
    for(int i = pivot+1;i<=size2;i++){
        totalRightXor ^= i;
    }
    for (int i = 0; i < size; i++)
    {
        if (i<=pivot)
        {
            arrLeftXor ^= arr[i];
        }
        else{
            arrRightXor ^= arr[i];
        }
        
    }
    
    int one = totalLeftXor ^ arrLeftXor;
    int two = totalRightXor ^ arrRightXor;
    cout << one<< two << endl;
    // return {totalLeftXor^arrLeftXor, totalRightXor^arrRightXor};
}
int main(){
    int arr[] = {1, 2, 5, 6};
    int size = 4;
    twoMissing(arr, size);
    return 0;
}