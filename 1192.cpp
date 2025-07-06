#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int time = 1;
    void dfs(int node, int parent, vector<int> &vis, vector<vector<int>> &adj, vector<int> &tin, vector<int> &low, vector<vector<int>> &bridges)
    {
        vis[node] = 1;
        tin[node] = low[node] = time;
        time++;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, node, vis, adj, tin, low,bridges);
                low[node] = min(low[node], low[it]);
                if (low[it] > tin[node])
                {
                    bridges.push_back({node, it});
                }
            }
            else if (vis[it] && it != parent)
            {
                low[node] = min(low[node], low[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {

        vector<vector<int>> adj(n);
        for (auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        vector<int> tin(n);
        vector<int> low(n);

        vector<vector<int>> bridges;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,vis,adj,tin,low,bridges);
            }
        }

        return bridges;
    }
};

int main()
{
    Solution sol;

    int n = 4;
    vector<vector<int>> connections = {
        {0, 1}, {1, 2}, {2, 0}, {1, 3}};

    vector<vector<int>> result = sol.criticalConnections(n, connections);

    for (auto &conn : result)
    {
        cout << "[" << conn[0] << ", " << conn[1] << "]" << endl;
    }

    return 0;
}
