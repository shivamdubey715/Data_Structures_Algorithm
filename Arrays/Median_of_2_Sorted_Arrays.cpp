#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
         if(array2.size() < array1.size()) 
        return MedianOfArrays(array2,array1);
        
        int n1 = array1.size();
        int n2 = array2.size();
        int low = 0, high = n1;
        
        while(low <= high){
            int cut1 = (low+high) >> 1;
            int cut2 = (n1+n2+1)/2 - cut1;
            
            int left1 = cut1 == 0 ? INT_MIN : array1[cut1-1];
            int left2 = cut2 == 0 ? INT_MIN : array2[cut2-1];
            
            int right1 = cut1 == n1 ? INT_MAX : array1[cut1];
            int right2 = cut2 == n2 ? INT_MAX : array2[cut2];
            
            if(left1 <= right2 && left2 <= right1){
                if((n1+n2)%2 == 0)
                return (max(left1,left2)+ min(right1,right2))/2.0;
                else 
                return max(left1,left2);
            }
            else if(left1 > right2) {
                high = cut1 - 1;
            }
            else {
                low = cut1 + 1;
            }
        }
    return 0.0;
    
    }
};

int main(){
    vector<int> array1 = {1, 3, 4, 7, 10, 12};
    vector<int> array2 = {2, 3, 6, 15};
    Solution ob;
    cout << ob.MedianOfArrays(array1, array2) << endl;
    return 0;
}