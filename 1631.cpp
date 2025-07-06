#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {

        int n = heights.size();
        int m = heights[0].size();

        pair<int, int> source = {0, 0};
        pair<int, int> dest = {n - 1, m - 1};
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, source.first, source.second});
        dist[source.first][source.second] = 0;

        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

        while (!pq.empty())
        {
            auto t = pq.top();
            int row = get<1>(t);
            int col = get<2>(t);
            int difference = get<0>(t);
            pq.pop();

            if(row == dest.first && col == dest.second){
                return dist[dest.first][dest.second];
            }

            for (int i = 0; i < 4; i++)
            {

                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && max(abs(heights[nrow][ncol] - heights[row][col]), difference) < dist[nrow][ncol])
                {

                    dist[nrow][ncol] = max(abs(heights[nrow][ncol] - heights[row][col]), difference);
                    pq.push({dist[nrow][ncol], nrow, ncol});
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

    // Example 1
    vector<vector<int>> heights1 = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    cout << "Output: " << sol.minimumEffortPath(heights1) << endl;

    // Example 2
    vector<vector<int>> heights2 = {{1, 2, 3}, {3, 8, 4}, {5, 3, 5}};
    cout << "Output: " << sol.minimumEffortPath(heights2) << endl;

    // Example 3
    vector<vector<int>> heights3 = {
        {1, 2, 1, 1, 1},
        {1, 2, 1, 2, 1},
        {1, 2, 1, 2, 1},
        {1, 2, 1, 2, 1},
        {1, 1, 1, 2, 1}};
    cout << "Output: " << sol.minimumEffortPath(heights3) << endl;

    return 0;
}
