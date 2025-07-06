#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// BFS

// class Solution
// {
// public:
//     bool bfs(int start, vector<vector<int>> adj, vector<int> &vis)
//     {
//         queue<int> q;
//         q.push(start);
//         vis[start] = 0;

//         while (!q.empty())
//         {
//             int front = q.front();
//             q.pop();

//             for (auto it : adj[front])
//             {
//                 if (vis[it] == -1)
//                 {
//                     vis[it] = !vis[front];
//                     q.push(it);
//                 }
//                 else if (vis[it] == vis[front])
//                 {
//                     return false;
//                 }
//             }
//         }

//         return true;
//     }

//     bool isBipartite(vector<vector<int>> &graph)
//     {
//         int n = graph.size();
//         vector<int> visited(n, -1);

//         for (int i = 0; i < n; i++)
//         {
//             if (visited[i] == -1)
//             {
//                 if (bfs(i, graph, visited) == false)
//                 {
//                     return false;
//                 };
//             }
//         }

//         return true;
//     }
// };

// DFS

class Solution
{
public:
    bool dfs(int start, int col, vector<vector<int>> adj, vector<int> &vis)
    {
        vis[start] = col;
        for (auto it : adj[start])
        {
            if (vis[it] == -1)
            {
                vis[it] = !vis[start];
                if(dfs(it,!col,adj,vis)== false){
                    return false;
                }
            }
            else if (vis[it] == vis[start])
            {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> visited(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == -1)
            {
                if (dfs(i, 0, graph, visited) == false)
                {
                    return false;
                };
            }
        }

        return true;
    }
};

int main()
{

    vector<vector<int>> graph = {
        {1, 2, 3},
        {0, 2},
        {0, 1, 3},
        {0, 2}};

    Solution sol;
    bool result = sol.isBipartite(graph);

    cout << (result ? "true" : "false") << endl;

    return 0;
}
