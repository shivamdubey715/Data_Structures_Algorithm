// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int x1, y1;
//         cin >> x1 >> y1;
//         for (int i = 1; i <= x1; ++i)
//         {
//             for (int j = 1; j <= y1; ++j)
//             {
//                 if (i % 2 == 0)
//                 {
//                     if (i % 4 == 0 && j == 1)
//                     {
//                         cout << "# ";
//                         continue;
//                     }

//                     else if (i % 2 ==0 && i % 4 != 0 && j == y1)
//                     {
//                         cout << "# ";
//                         break;
//                     }
//                     cout << ". ";
//                 }
//                 else
//                 {
//                     cout << "# ";
//                 }
//             }
//             cout << endl;
//         }
//     }
//     return 0;
// }


#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    // bool is = true;
    for(int i=1;i<=n;i++){
        if(i%4==2){
            for(int i=1;i<m;i++){
                cout<<".";
            }
            cout<<"#";
        }else if(i%4==0){
           cout<<"#";
           for(int i=1;i<m;i++){
                cout<<".";
            } 
        }else{
            for(int i=1;i<=m;i++){
                cout<<"#";
            }
        }
        cout<<"\n";
    }
    return 0;
}