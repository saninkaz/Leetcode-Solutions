#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {

        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        int count = 0;
        for (auto &road : roads)
        {
            int u = road[0], v = road[1], time = road[2];
            adj[u].emplace_back(v, time);
            adj[v].emplace_back(u, time);
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty())
        {
            long long distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                long long wt = it.second;
                if (distance + wt < dist[it.first])
                {
                    ways[it.first] = ways[node];
                    dist[it.first] = distance + wt;
                    pq.push({dist[it.first], it.first});
                }
                else if (dist[it.first] == distance + wt)
                {
                    ways[it.first] = (ways[it.first] + ways[node]) % MOD;
                }
            }
        }

        for (int i = 0; i < dist.size(); i++)
        {
            if (dist[i] == LLONG_MAX)
            {
                dist[i] = -1;
            }
        }

        return ways[n - 1];
    }
};

int main()
{
    Solution sol;
    int n = 7;
    vector<vector<int>> roads = {
        {0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};

    int result = sol.countPaths(n, roads);
    cout << "Number of ways: " << result << endl;

    return 0;
}
