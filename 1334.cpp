#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    dist[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int distance = edges[i][2];

            dist[u][v] = distance;
            dist[v][u] = distance;
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        int mx = INT_MIN;
        int mn = INT_MAX;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][j] != 0 && dist[i][j] <= distanceThreshold)
                {
                    count++;
                }
            }
            if(count <= mn){
                mn = count;
                mx =max(i,mx);
            }
            count = 0;
        }

        return mx;
    }
};

int main()
{
    Solution sol;

    // Example 1
    int n1 = 4;
    vector<vector<int>> edges1 = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    int threshold1 = 4;
    cout << "Output: " << sol.findTheCity(n1, edges1, threshold1) << endl;

    // Example 2
    int n2 = 5;
    vector<vector<int>> edges2 = {{0, 1, 2}, {0, 4, 8}, {1, 2, 3}, {1, 4, 2}, {2, 3, 1}, {3, 4, 1}};
    int threshold2 = 2;
    cout << "Output: " << sol.findTheCity(n2, edges2, threshold2) << endl;

    return 0;
}
