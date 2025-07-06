#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void dfs(int sr, int sc, vector<vector<int>> &grid, vector<vector<int>> &visited, int delrow[], int delcol[], int n, int m)
    {
        visited[sr][sc] = 1;
        for (int i = 0; i < 4; i++)
        {
            int nrow = sr + delrow[i];
            int ncol = sc + delcol[i];

            if (nrow < n && ncol < m && nrow >= 0 && ncol >= 0 && grid[nrow][ncol] == 1 && visited[nrow][ncol] == 0)
            {

                dfs(nrow, ncol, grid, visited, delrow, delcol, n, m);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid)
    {

        int n = grid.size();
        int m = grid[0].size();
        int count =0;

        vector<vector<int>> visited(n, vector<int>(m, 0));

        int row[2] = {0, n - 1};
        int col[2] = {0, m - 1};
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, -1, 0, 1};

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[row[i]][j] == 1)
                {
                    dfs(row[i], j, grid, visited, delrow, delcol, n, m);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (grid[i][col[j]] == 1)
                {
                    dfs(i, col[j], grid, visited, delrow, delcol, n, m);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {

    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    Solution sol;
    int result = sol.numEnclaves(grid);

    cout << "Output: " << result << endl;

    return 0;
}
