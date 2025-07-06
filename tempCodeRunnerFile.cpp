class Solution
{
private:
    int rec(int i, int j, vector<vector<int>> &matrix, int m, int n)
    {
        if (i == 0)
        {
            return matrix[0][j];
        }

        if (j < 0 || j >= n)
        {
            return INT_MAX;
        }

        int dl = matrix[i][j] + rec(i - 1, j - 1, matrix, m, n);
        int d = matrix[i][j] + rec(i - 1, j, matrix, m, n);
        int dr = matrix[i][j] + rec(i - 1, j + 1, matrix, m, n);

        return min(dl, min(d, dr));
    }

public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int mn = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            mn = min(mn, rec(m - 1, i, matrix, m, n));
        }
        return mn;
    }
};