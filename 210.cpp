#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses);
        vector<int> inDegree(numCourses);
        vector<int> result;

        for (int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }

        if (bfs(adj, visited, inDegree, result) == true)
        {
            return {};
        }
        return result;
    }
};

int main()
{
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    Solution sol;
    vector<int> order = sol.findOrder(numCourses, prerequisites);

    for (int course : order)
    {
        cout << course << " ";
    }
    cout << endl;

    return 0;
}
