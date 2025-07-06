#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<int>> dalmurecio = edges;


        vector<vector<tuple<int, int, int>>> adj(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], start = e[2], end = e[3];
            adj[u].emplace_back(v, start, end);
        }
        
        using T = pair<int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        vector<int> earliest(n, INT_MAX); 
        pq.push({0, 0});                
        earliest[0] = 0;

        while (!pq.empty()) {
            auto [currTime, u] = pq.top();
            pq.pop();

           
            if (currTime > earliest[u]) continue;

            
            for (auto& [v, start, end] : adj[u]) {
                if (currTime > end) continue; 

                int nextTime = max(currTime, start) + 1;

                if (nextTime < earliest[v]) {
                    earliest[v] = nextTime;
                    pq.push({nextTime, v});
                }
            }
        }

        return (earliest[n - 1] == INT_MAX) ? -1 : earliest[n - 1];
    }
};
