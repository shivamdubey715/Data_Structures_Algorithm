// #include <bits/stdc++.h>
// using namespace std;

// int MaxNonAdjacentAddition(vector<int> arr)
// {
//     int size = arr.size();
//     int prev = arr[0], prev2 = 0, cur;
//     for (int i = 0; i < size; i++)
//     {
//         int pick = arr[i];
//         if (i > 1)
//         {
//             pick += prev2;
//         }
//         int notpick = 0 + prev;
//         cur = max(pick, notpick);
//         prev2 = prev;
//         prev = cur;
//     }
//     return prev;
// }
// int maxRobber(vector<int> arr){
//     vector<int> temp1, temp2;
//     int n = arr.size();
//     for (int i = 0; i < n; i++)
//     {
//         if (i!=0)
//         {
//             temp1.push_back(arr[i]);
//         }
//         if (i!=n-1)
//         {
//             temp2.push_back(arr[i]);
//         }
//     }
//     return max(MaxNonAdjacentAddition(temp1), MaxNonAdjacentAddition(temp2));
    
// }
// int main() {

//   vector<int> arr{1,5,1,2,6};
//   cout<<maxRobber(arr)<<endl;
//   return 0;
// }



#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        // char ans = 'z';
        if(s.size()==2){
            cout << s.back()<<endl;
        }
        else{
            for(int i=0;s[i] != '\0';i++){
                char ans = *min_element(s.begin(), s.end());
                cout << ans <<endl;
            }
        }
        
    }
    return 0;
}