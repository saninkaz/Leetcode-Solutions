#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
private:
    bool check(int i, int j, vector<string> &temp, int n)
    {

        for (int c = 0; c < j; c++)
        {
            if (temp[i][c] == 'Q')
            {
                return false;
            }
        }

        int row = i;
        int col = j;
        while (row < n && col >= 0)
        {
            if (temp[row][col] == 'Q')
            {
                return false;
            }
            row++;
            col--;
        }

        row = i;
        col = j;
        while (row >= 0 && col >= 0)
        {
            if (temp[row][col] == 'Q')
            {
                return false;
            }
            row--;
            col--;
        }

        return true;
    }

    void rec(int col, int n, vector<string> &temp, vector<vector<string>> &solutions)
    {
        if (col == n)
        {
            solutions.push_back(temp);
        }
        for (int row = 0; row < n; row++)
        {
            if (check(row, col, temp, n))
            {
                temp[row][col] = 'Q';
                rec(col + 1, n, temp, solutions);
                temp[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> solutions;
        vector<string> temp(n, string(n, '.'));

        rec(0, n, temp, solutions);

        return solutions;
    }
};

int main()
{
    Solution sol;

    int n = 4;
    vector<vector<string>> results = sol.solveNQueens(n);

    // Print results
    for (const auto &board : results)
    {
        for (const string &row : board)
        {
            cout << row << endl;
        }
        cout << "-----" << endl;
    }

    return 0;
}
