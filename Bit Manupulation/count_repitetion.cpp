
//Brute force method
//Time complexity: O(n^2)
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[10] = {2, 2, 3, 3, 5, 6, 6, 7, 8, 8};
    for (int i = 0; i < 10; i++)
    {
        int count = 0;
        for (int j = 0; j < 10; j++)
        {
            if (a[j]==a[i])
            {
                count++;
            }
        }
        if (count==1)
        {
            cout << a[i] << endl;
        } 
    }
    
}



//Mthode 2:
// Time complexity: O(nlogn)
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int a[10] = {2, 2, 3, 3, 5, 6, 6, 7, 8, 8};
//     map<int, int> mpp;
//     for (int i = 0; i < 10; i++)
//     {
//         mpp[a[i]]++;
//     }
//     for (auto it:mpp){
//         if (it.second == 1)
//         {
//             cout << it.first << endl;
//         }
//     }
//     return 0;
// }
// 