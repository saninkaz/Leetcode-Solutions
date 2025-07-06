#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {

        vector<vector<pair<int, int>>> adj(n);
        vector<int> dist(n, INT_MAX);

        for (int i = 0; i < flights.size(); i++)
        {
            int u = flights[i][0];
            int v = flights[i][1];
            int distance = flights[i][2];

            adj[u].push_back({v, distance});
        }

        queue<tuple<int, int, int>> q;

        dist[src] = 0;
        q.push({0, 0, src});

        while (!q.empty())
        {
            auto t = q.front();
            int stops = get<0>(t);
            int distance = get<1>(t);
            int node = get<2>(t);
            q.pop();

            for (auto it : adj[node])
            {
                int wt = it.second;
                if(stops + 1>k && it.first !=dst){
                    continue;
                }
                if (distance + wt < dist[it.first] && stops <= k)
                {
                    dist[it.first] = distance + wt;
                    q.push({stops + 1, dist[it.first], it.first});
                }
            }
        }

        if(dist[dst] == INT_MAX) return -1;

        return dist[dst];
    }
};

int main()
{
    Solution sol;

    int n = 4;
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 0, 100},
        {1, 3, 600},
        {2, 3, 200}};
    int src = 0;
    int dst = 3;
    int k = 1;

    int result = sol.findCheapestPrice(n, flights, src, dst, k);
    cout << result << endl;

    return 0;
}
