#include <iostream>
#include <vector>
using namespace std;

// Solution 1 using adjacency list

// class Solution {
// public:

//     void dfs(vector<vector<int>> adj, vector<int> &vis, int node)
//     {
//         vis[node] = 1;
//         for (auto it : adj[node])
//         {
//             if (!vis[it])
//                 dfs(adj, vis, it);
//         }
//     }

//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int ans;
//         int n = isConnected.size();

//         vector<vector<int>> adj(n);

//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 if(isConnected[i][j] && i!=j){
//                     adj[i].push_back(j);
//                     adj[j].push_back(i);
//                 }
//             }
//         }

//         vector<int> vis(n);
//         int count=0;

//         for(int i=0;i<n;i++){
//             if(!vis[i]){
//                 count++;
//                 dfs(adj,vis,i);
//             }
//         }
//         return count;
//     }
// };

// Solution 2 (using adjacency matrix)

class Solution
{
public:
    void dfs(int node, vector<vector<int>> &isConnected, vector<bool> &visited, int n)
    {
        visited[node] = true;
        for (int j = 0; j < n; ++j)
        {
            if (isConnected[node][j] == 1 && !visited[j])
            {
                dfs(j, isConnected, visited, n);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                provinces++;
                dfs(i, isConnected, visited, n);
            }
        }

        return provinces;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}};

    int provinces = sol.findCircleNum(isConnected);
    cout << "Number of provinces: " << provinces << endl;

    return 0;
}
