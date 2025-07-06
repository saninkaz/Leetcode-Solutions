#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {

        vector<vector<pair<int, int>>> adj(n + 1);
        vector<int> dist(n + 1, INT_MAX);

        for (int i = 0; i < times.size(); i++)
        {
            int u = times[i][0];
            int v = times[i][1];
            int distance = times[i][2];

            adj[u].push_back({v, distance});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[k] = 0;
        pq.push({0, k});
        int mx = INT_MIN;

        while (!pq.empty())
        {
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                int wt = it.second;
                if (distance + wt < dist[it.first])
                {
                    mx = max(mx,distance + wt);
                    dist[it.first] = distance + wt;
                    pq.push({dist[it.first], it.first});
                }
            }
        }

        for (int i = 1; i <=n; i++)
        {
            if (dist[i] == INT_MAX)
            {
                return -1;
            }
        }

        dist[0] = INT_MIN;
        return *max_element(dist.begin(), dist.end());
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> times = {
        {1,2,1}};
    int n = 2; // number of nodes
    int k = 2; // source node

    int result = sol.networkDelayTime(times, n, k);
    cout << result << endl;

    return 0;
}
