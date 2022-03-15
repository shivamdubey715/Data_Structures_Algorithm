#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    double kthElement(vector<int>& array1, vector<int>& array2, int k)
    {
        if(array2.size() < array1.size()) 
        return kthElement(array2,array1, k);
        
        int n1 = array1.size();
        int n2 = array2.size();
        int low = max(0, k - n2), high = min(k, n1);
        
        while(low <= high){
            int cut1 = (low+high) >> 1;
            int cut2 = (n1+n2+1)/2 - cut1;
            
            int left1 = cut1 == 0 ? INT_MIN : array1[cut1-1];
            int left2 = cut2 == 0 ? INT_MIN : array2[cut2-1];
            
            int right1 = cut1 == n1 ? INT_MAX : array1[cut1];
            int right2 = cut2 == n2 ? INT_MAX : array2[cut2];
            
            if(left1 <= right2 && left2 <= right1){
                return max(left1, left2);
            }
            else if(left1 > right2) {
                high = cut1 - 1;
            }
            else {
                low = cut1 + 1;
            }
        }
    return 1;
    
    }
};

int main(){
    vector<int> array1 = {1, 3, 4, 7, 10, 12};
    vector<int> array2 = {2, 3, 6, 15};
    Solution ob;
    cout << ob.kthElement(array1, array2, 7) << endl;
    return 0;
}