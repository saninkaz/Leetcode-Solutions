#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {

        int n = grid.size();

        pair<int, int> source = {0, 0};
        pair<int, int> dest = {n - 1, n - 1};
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        if (grid[source.first][source.second] == 1 || grid[dest.first][dest.second] == 1)
        {
            return -1;
        }

        queue<tuple<int, int, int>> q;
        q.push({source.first, source.second, 1});
        dist[source.first][source.second] = 1;

        while (!q.empty())
        {
            auto t = q.front();
            int row = get<0>(t);
            int col = get<1>(t);
            int distance = get<2>(t);
            q.pop();

            for (int delrow = -1; delrow <= 1; delrow++)
            {
                for (int delcol = -1; delcol <= 1; delcol++)
                {
                    int nrow = row + delrow;
                    int ncol = col + delcol;
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0 && distance + 1 < dist[nrow][ncol])
                    {
                        if (nrow == dest.first && ncol == dest.second)
                        {
                            return distance +1;
                        }

                        dist[nrow][ncol] = distance + 1;
                        q.push({nrow, ncol, distance + 1});
                    }
                }
            }
        }

        if (dist[dest.first][dest.second] == INT_MAX)
        {
            return -1;
        }

        return dist[dest.first][dest.second];
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {
        {0, 1},
        {1, 0}};

    int result = sol.shortestPathBinaryMatrix(grid);
    cout << result << endl;

    return 0;
}
