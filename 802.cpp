#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int i, vector<vector<int>> graph, int n, vector<int> &visited, vector<int> &pathVis, vector<int> &check)
    {
        visited[i] = 1;
        pathVis[i] = 1;

        for (auto it : graph[i])
        {

            if (!visited[it])
            {
                dfs(it, graph, n, visited, pathVis, check);
            }
            if (pathVis[it])
            {
                return;
            }
        }

        check[i] = 1;
        pathVis[i] = 0;
    }

    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();

        vector<int> visited(n);
        vector<int> pathVis(n);
        vector<int> check(n);

        vector<int> result;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, graph, n, visited, pathVis, check);
            }
        }

        for(int i=0;i<n;i++){
            if(check[i]){
                result.push_back(i);
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};

    vector<int> safeNodes = sol.eventualSafeNodes(graph);
    for (int node : safeNodes)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
