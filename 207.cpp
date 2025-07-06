#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

// Using dfs

// class Solution
// {
// private:
//     bool dfs(int start, vector<vector<int>> &adj, vector<int> &visited, vector<int> &path, vector<int> &result)
//     {
//         visited[start] = 1;
//         path[start] = 1;

//         for (auto it : adj[start])
//         {
//             if (!visited[it])
//             {
//                 if (dfs(it, adj, visited, path, result) == true)
//                 {
//                     return true;
//                 }
//             }
//             else if(path[it]){
//                 return true;
//             }
//         }
//         path[start] = 0;
//         return false;
//     }

// public:
//     bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
//     {

//         vector<vector<int>> adj(numCourses);
//         vector<int> visited(numCourses);
//         vector<int> path(numCourses);
//         vector<int> result;

//         for (int i = 0; i < prerequisites.size(); i++)
//         {
//             adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
//         }

//         for (int i = 0; i < numCourses; i++)
//         {
//             if (!visited[i])
//             {
//                 if (dfs(i, adj, visited, path, result) == true)
//                 {
//                     return false;
//                 }
//             }
//         }

//         return true;
//     }
// };

// Using bfs {Kahns algorithm} (most optimal)

class Solution
{
private:
    bool bfs(vector<vector<int>> &adj, vector<int> &visited, vector<int> &inDegree, vector<int> &result)
    {
        queue<int> q;
        int n = inDegree.size();

        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            result.push_back(node);

            for (auto it : adj[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        if (result.size() != n)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {

        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses);
        vector<int> inDegree(numCourses);
        vector<int> result;

        for (int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            inDegree[prerequisites[i][1]]++;
        }

        if (bfs(adj, visited, inDegree, result) == true)
        {
            return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;

    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};

    bool result = sol.canFinish(numCourses, prerequisites);

    cout << (result ? "true" : "false") << endl;

    return 0;
}
