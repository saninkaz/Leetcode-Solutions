#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int rec(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
        {
            return grid[0][0];
        }
        if (i < 0 || j < 0)
        {
            return INT_MAX;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int mn = INT_MAX;

        int up = rec(i - 1, j, grid, dp);
        int left = rec(i, j - 1, grid, dp);

        up = up == INT_MAX ? INT_MAX : up + grid[i][j];
        left = left == INT_MAX ? INT_MAX : left + grid[i][j];
        return dp[i][j] = min(up, left);
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        int sum = 0;
        sum = rec(m - 1, n - 1, grid, dp);
        return sum;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> grid1 = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    vector<vector<int>> grid2 = {{1, 2, 3}, {4, 5, 6}};

    cout << "Minimum path sum for grid1: " << sol.minPathSum(grid1) << endl;
    cout << "Minimum path sum for grid2: " << sol.minPathSum(grid2) << endl;

    return 0;
}
