#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> rank, parent;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void UnionByRank(int u, int v)
    {
        int up_u = findUPar(u);
        int up_v = findUPar(v);
        if (up_u == up_v)
            return;
        if (rank[up_u] < rank[up_v])
        {
            parent[up_u] = up_v;
        }
        else if (rank[up_v] < rank[up_u])
        {
            parent[up_v] = up_u;
        }
        else
        {
            parent[up_v] = up_u;
            rank[up_u]++;
        }
    }
};

class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {

        DisjointSet ds(n);
        int numberOfEdges = connections.size();
        for (auto it : connections)
        {
            int u = it[0];
            int v = it[1];
            if (ds.findUPar(u) != ds.findUPar(v))
            {
                ds.UnionByRank(u, v);
            }
        }

        int numberofComponents = 0;

        for (int i=0;i<n;i++){
            if(ds.parent[i]==i) numberofComponents++;
        }

        if(n-1>numberOfEdges){
            return -1;
        }

        return numberofComponents-1;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> connections(m, vector<int>(2));
    for (int i = 0; i < m; ++i)
    {
        cin >> connections[i][0] >> connections[i][1];
    }

    Solution sol;
    int result = sol.makeConnected(n, connections);
    cout << result << endl;

    return 0;
}
