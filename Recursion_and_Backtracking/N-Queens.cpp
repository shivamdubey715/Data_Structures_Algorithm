#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    bool isSafe(int row, int col, vector<string> board, int n)
    {
        //We dont need to check right column, row, diagonal as we are iterating from left to right
        int drow = row, dcol = col;  // drow = duplicate row and dcol = duplicate column
        //For left upper diagonal elements:
        while (row >= 0 and col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row--, col--;
        }
        row = drow, col = dcol;

        while (col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }
        col = dcol;
        row = drow;
        //For left lower diagonal elements:
        while (row < n && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            col--, row++;
        }

        return true;
    }
    void solve(int col, vector<vector<int>> &ans, vector<string> &board, int n, vector<int> &sol)
    {
        if (col == n)
        {
            ans.push_back(sol);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                sol[col] = row + 1;
                solve(col + 1, ans, board, n, sol);
                board[row][col] = '.';
                sol[col] = 0;
            }
        }
    }
    vector<vector<int>> nQueen(int n)
    {
        vector<vector<int>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
            board[i] = s;
        vector<int> sol(n, 0);
        solve(0, ans, board, n, sol);
        return ans;
    }
};

int main()
{
    solution ob;
    vector<vector<int>> ans = ob.nQueen(4);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (int u : ans[i])
        {
            cout << u << " ";
        }
        cout << "]";
    }
    return 0;
}