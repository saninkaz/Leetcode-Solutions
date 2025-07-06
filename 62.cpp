#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int rec(int i, int j, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
        {
            return 1;
        }
        if (i < 0 || j < 0)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int up = rec(i - 1, j, dp);
        int left = rec(i, j - 1, dp);

        return dp[i][j] = up + left;
    }

public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int sum = rec(m - 1, n - 1, dp);
        return sum;
    }
};

int main()
{
    Solution sol;
    int m1 = 3, n1 = 7;
    int m2 = 3, n2 = 2;

    cout << "Unique paths for 3x7 grid: " << sol.uniquePaths(m1, n1) << endl;
    cout << "Unique paths for 3x2 grid: " << sol.uniquePaths(m2, n2) << endl;

    return 0;
}
