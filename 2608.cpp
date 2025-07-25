#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int bfs(int start, vector<vector<int>> &adj)
    {
        queue<int> q;
        int n = adj.size();
        vector<int> visited(n, 0);
        vector<int> parent(n, -1);
        vector<int> dist(n, 0);

        q.push(start);
        dist[start] = 0;
        visited[start] = 1;
        parent[start] = -1;
        int len = 0;
        int mn = INT_MAX;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it : adj[node])
            {
                if (!visited[it])
                {
                    visited[it] = 1;
                    parent[it] = node;
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
                else if (parent[node] != it)
                {
                    len = dist[it] + dist[node] + 1;
                    mn = min(len, mn);
                }
            }
        }

        return mn;
    }

public:
    int findShortestCycle(int n, vector<vector<int>> &edges)
    {

        vector<vector<int>> adj(n);

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int mn = INT_MAX;

        for (int i = 0; i < n; i++)
        {

            mn = min(bfs(i, adj), mn);
        }
        return mn == INT_MAX ? -1 : mn;
    }
};

int main()
{
    Solution sol;
    int n = 4;
    vector<vector<int>> edges = {{1, 2}, {0, 1}, {3, 2}, {1, 3}};

    int result = sol.findShortestCycle(n, edges);
    cout << "Length of the shortest cycle: " << result << endl;

    return 0;
}
