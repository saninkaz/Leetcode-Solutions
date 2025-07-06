#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int rec(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp)
    {
        if (i == n - 1)
        {
            return triangle[i][j];
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int dg = triangle[i][j] + rec(i + 1, j + 1, triangle, n, dp);
        int down = triangle[i][j] + rec(i + 1, j, triangle, n, dp);

        return dp[i][j] = min(dg, down);
    }

public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));

        int mn = rec(0, 0, triangle, m, dp);
        return mn;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> triangle1 = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}};

    vector<vector<int>> triangle2 = {
        {-10}};

    cout << "Minimum path sum for triangle1: " << sol.minimumTotal(triangle1) << endl;
    cout << "Minimum path sum for triangle2: " << sol.minimumTotal(triangle2) << endl;

    return 0;
}
