#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<string>> Partition(string s){
        vector<vector<string>> res;
        vector<string> path;
        func(0, s, path, res);
        return res;
    }
    void func(int index, string s, vector<string> path, vector<vector<string>> res){
        if (index == s.size())
        {
            res.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); i++){
            if(isPalindrome(s, index, i)){
                path.push_back(s.substr(index, i - index + 1));
                func(i + 1, s, path, res);
                path.pop_back();
            }
        }
        
    }
    bool isPalindrome(string s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
};

// int main(){
//     Solution ob;
//     vector<vector<string>> ans = ob.Partition("aabb");
//     for (char i = 0; i < ans.size(); i++)
//     {
//         cout << "[";
//         for (string u : ans[i])
//         {
//             cout << u << " ";
//         }
//         cout << "]";
//     }
// }