#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
#include <climits>

using namespace std;

class Solution
{
public:
    int bfs(queue<pair<pair<int, int>, int>> q, vector<vector<int>> &grid, vector<vector<int>> &visited, int m, int n)
    {

        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, -1, 0, 1};
        int count = 0;
        int countm = 0;

        while (!q.empty())
        {
            int sr = q.front().first.first;
            int sc = q.front().first.second;
            count = q.front().second;
            countm = max(countm, count);
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = sr + delrow[i];
                int ncol = sc + delcol[i];

                if (nrow < m && ncol < n && nrow >= 0 && ncol >= 0 && grid[nrow][ncol] == 1 && visited[nrow][ncol] == 0)
                {
                    visited[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, count + 1});
                }
            }
        }

        return countm;
    }

    int orangesRotting(vector<vector<int>> &grid)
    {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        int sr, sc;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
                else
                {
                    visited[i][j] = 0;
                }
            }
        }

        int count = bfs(q, grid, visited, m, n);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j] != 2 && grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return count;
    }
};

int main()
{
    Solution sol;

    // Example Input 1
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}};

    int result = sol.orangesRotting(grid);
    cout << "Minimum number of minutes: " << result << endl;

    return 0;
}
