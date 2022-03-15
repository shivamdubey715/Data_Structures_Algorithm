/*
We have to convert upper case to lower case and vice versa.
*/

// Method 1:
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// int main()
// {
//     string str1 = "nuiehfvdhfhebvdhfbcv";
//     string str2 = "HIOHANAJKDLNADNKLCV";
//     for (int i = 0; i < str1.length(); i++)
//     {
//         if (str1[i] >= 'a' && str1[i] <= 'z') // if we substract 'A' from 'a we get 32 which is a ascci value so it means if we want to convert lower case to upper case we need to substract 32 from it's upper case. Similary to convert Upper case to Lower case we need to add 32 to it's upper case.
//         {
//             str1[i] -= 32;
//         }
//     }
//     for (int i = 0; i < str2.length(); i++)
//     {
//         if (str2[i] >= 'A' && str2[i] <= 'Z') // Similary to convert Upper case to Lower case we need to add 32 to it's upper case.
//         {
//             str2[i] += 32;
//         }
//     }
//     cout << str1 << endl;
//     cout << str2 << endl;
//     ;
//     cout << endl;
//     return 0;
// }

// Method 2:
int main()
{
    string str1 = "nuiehfvdhfhebvdhfbcv";
    string str2 = "HIOHANAJKDLNADNKLCV";
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    cout << str1 << endl << str2 << endl;
    return 0;
}