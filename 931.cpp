#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Recursion

// class Solution
// {
// private:
//     int rec(int i, int j, vector<vector<int>> &matrix, int m, int n, vector<vector<int>> &dp)
//     {
//         if (j < 0 || j >= n)
//         {
//             return INT_MAX;
//         }
//         if (i == 0)
//         {
//             return matrix[0][j];
//         }

//         if (dp[i][j] != INT_MAX)
//             return dp[i][j];

//         int dl = rec(i - 1, j - 1, matrix, m, n, dp);
//         int d = rec(i - 1, j, matrix, m, n, dp);
//         int dr = rec(i - 1, j + 1, matrix, m, n, dp);

//         dl = (dl == INT_MAX) ? INT_MAX : matrix[i][j] + dl;
//         d = (d == INT_MAX) ? INT_MAX : matrix[i][j] + d;
//         dr = (dr == INT_MAX) ? INT_MAX : matrix[i][j] + dr;

//         return dp[i][j] = min(dl, min(d, dr));
//     }

// public:
//     int minFallingPathSum(vector<vector<int>> &matrix)
//     {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

//         int mn = INT_MAX;

//         for (int i = 0; i < n; i++)
//         {
//             mn = min(mn, rec(m - 1, i, matrix, m, n, dp));
//         }
//         return mn;
//     }
// };

// Tabulation

class Solution
{

public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int j = 0; j < n; j++)
        {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int dl = INT_MAX;
                int dr = INT_MAX;
                if (j - 1 >= 0)
                {
                    dl = dp[i - 1][j - 1] + matrix[i][j];
                }
                int d = dp[i - 1][j] + matrix[i][j];
                if (j + 1 < n)
                {
                    dr = dp[i - 1][j + 1] + matrix[i][j];
                }

                dp[i][j] = min(dl, min(d, dr));
            } 
        }

        int mn = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            mn = min(mn, dp[m - 1][i]);
        }

        return mn;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> matrix1 = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    vector<vector<int>> matrix2 = {{-19, 57}, {-40, -5}};

    cout << "Min falling path sum for matrix1: " << sol.minFallingPathSum(matrix1) << endl;
    cout << "Min falling path sum for matrix2: " << sol.minFallingPathSum(matrix2) << endl;

    return 0;
}
