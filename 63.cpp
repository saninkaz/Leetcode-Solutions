#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int rec(int i, int j, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp)
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
        int up = 0;
        int left = 0;

        if (i - 1 >= 0 && obstacleGrid[i - 1][j] == 0)
        {
            up = rec(i - 1, j, obstacleGrid, dp);
        }
        if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0)
        {
            left = rec(i, j - 1, obstacleGrid, dp);
        }

        return dp[i][j] = up + left;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int sum = 0;

        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
        {
            return 0;
        }

        sum = rec(m - 1, n - 1, obstacleGrid, dp);
        return sum;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> grid1 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector<vector<int>> grid2 = {{0, 1}, {0, 0}};

    cout << "Unique paths for grid1: " << sol.uniquePathsWithObstacles(grid1) << endl;
    cout << "Unique paths for grid2: " << sol.uniquePathsWithObstacles(grid2) << endl;

    return 0;
}
