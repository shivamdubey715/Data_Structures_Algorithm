#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int majorityElement(int a[], int size)
    {
        int count = 1;
       int ansIndex = 0;
       for(int i=1;i<size;i++){
           
           
           if(a[i] == a[ansIndex]){
               count++;
           }
           else count--;
           
           if(count <= 0){
               count = 1;
               ansIndex = i;
           }
       }
       
       int freq  = 0;
       
       for(int i=0;i<size;i++){
           if(a[i] == a[ansIndex]){
               freq++;
           }
       }
       
       if(freq > size/2 )
            return a[ansIndex];
      
      return -1;
        
    }
};

int main(){
    int arr[] = {3, 1, 3, 3, 1, 3};
    Solution ob;
    cout << ob.majorityElement(arr, 6) << endl;
    return 0;
}