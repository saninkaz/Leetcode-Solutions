#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        using State = tuple<long long, int, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;

        vector<vector<array<long long, 2>>> dist(m, vector<array<long long, 2>>(n, {LLONG_MAX, LLONG_MAX}));

        long long initialCost = 1;
        pq.push({initialCost, 0, 0, 1});
        dist[0][0][1] = initialCost;

        while (!pq.empty()) {
            auto [cost, i, j, parity] = pq.top();
            pq.pop();


            if (i == m - 1 && j == n - 1) return cost;

            if (dist[i][j][parity] < cost) continue; 

            if (parity == 0) {
                long long newCost = cost + waitCost[i][j];
                if (newCost < dist[i][j][1]) {
                    dist[i][j][1] = newCost;
                    pq.push({newCost, i, j, 1});
                }
            } else {
         
                if (i + 1 < m) {
                    long long moveCost = (i + 2) * (j + 1); 
                    long long newCost = cost + moveCost;
                    if (newCost < dist[i + 1][j][0]) {
                        dist[i + 1][j][0] = newCost;
                        pq.push({newCost, i + 1, j, 0});
                    }
                }

                if (j + 1 < n) {
                    long long moveCost = (i + 1) * (j + 2);
                    long long newCost = cost + moveCost;
                    if (newCost < dist[i][j + 1][0]) {
                        dist[i][j + 1][0] = newCost;
                        pq.push({newCost, i, j + 1, 0});
                    }
                }
            }
        }

        return -1; 
    }
};

