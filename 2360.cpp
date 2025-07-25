#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Soltion 1 Time limit exceeded

// class Solution
// {
// private:
//     void dfs(int start, int count, int &mx, vector<vector<int>> &adj, vector<int> &visited, vector<int> &pathVis, vector<int> &dist)
//     {
//         visited[start] = 1;
//         pathVis[start] = 1;

//         for (auto it : adj[start])
//         {
//             if (!visited[it])
//             {
//                 dist[it] = count + 1;
//                 dfs(it, count + 1, mx, adj, visited, pathVis, dist);
//             }
//             if (pathVis[it])
//             {
//                 int len = count + 1 - dist[it];
//                 mx = max(mx, len);
//             }
//         }
//         pathVis[start] = 0;
//     }

// public:
//     int longestCycle(vector<int> &edges)
//     {
//         int n = edges.size();
//         vector<vector<int>> adj(n);

//         for (int i = 0; i < n; i++)
//         {
//             int u = i;
//             int v = edges[i];
//             if(v!=-1)
//             adj[u].push_back(v);
//         }

//         int mx = INT_MIN;

//         for (int i = 0; i < n; i++)
//         {
//             vector<int> visited(n, 0);
//             vector<int> pathVis(n, 0);
//             vector<int> dist(n, 0);
//             dfs(i, 0, mx, adj, visited, pathVis, dist);
//         }

//         return mx == INT_MIN ? -1 : mx;
//     }
// };

// Solution 2

class Solution
{
private:
    void dfs(int start, int count, int &mx, vector<vector<int>> &adj, vector<int> &visited, vector<int> &pathVis, vector<int> &dist)
    {
        visited[start] = 1;
        pathVis[start] = 1;

        for (auto it : adj[start])
        {
            if (!visited[it])
            {
                dist[it] = count + 1;
                dfs(it, count + 1, mx, adj, visited, pathVis, dist);
            }
            if (pathVis[it])
            {
                int len = count + 1 - dist[it];
                mx = max(mx, len);
            }
        }
        pathVis[start] = 0;
    }

public:
    int longestCycle(vector<int> &edges)
    {
        int n = edges.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++)
        {
            int u = i;
            int v = edges[i];
            if (v != -1)
                adj[u].push_back(v);
        }

        int mx = INT_MIN;
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++)
        {
            vector<int> pathVis(n, 0);
            vector<int> dist(n, 0);
            dfs(i, 0, mx, adj, visited, pathVis, dist);
        }

        return mx == INT_MIN ? -1 : mx;
    }
};

int main()
{
    vector<int> edges = {2, -1, 3, 1};

    Solution sol;
    int result = sol.longestCycle(edges);

    cout << "Longest cycle length: " << result << endl;

    return 0;
}
