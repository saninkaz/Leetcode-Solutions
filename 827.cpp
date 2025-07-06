#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{

public:
    vector<int> rank, parent, size;

    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
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

    void UnionBySize(int u, int v)
    {
        int up_u = findUPar(u);
        int up_v = findUPar(v);
        if (up_u == up_v)
            return;
        if (size[up_u] < size[up_v])
        {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
        else
        {
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
};

class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int delrow[4] = {1, 0, -1, 0};
        int delcol[4] = {0, 1, 0, -1};

        DisjointSet ds(n * m);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    int node = (i * m) + j;
                    for (int z = 0; z < 4; z++)
                    {
                        int nrow = i + delrow[z];
                        int ncol = j + delcol[z];
                        int adjNode = (nrow * m) + ncol;
                        if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 1)
                        {
                            ds.UnionBySize(node, adjNode);
                        }
                    }
                }
            }
        }

        unordered_set<int> st;
        int sz = 0;
        int mx = INT_MIN;
        int flag = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    flag = 1;
                    int node = (i * m) + j;
                    for (int z = 0; z < 4; z++)
                    {
                        int nrow = i + delrow[z];
                        int ncol = j + delcol[z];
                        int adjNode = (nrow * m) + ncol;
                        if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 1)
                        {
                            st.insert(ds.findUPar(adjNode));
                        }
                    }

                    for (auto it : st)
                    {
                        sz += ds.size[it];
                    }
                    sz += 1; 
                    mx = max(sz, mx);
                    sz = 0;
                    st.clear();
                }
            }
        }
        if(!flag) return n*m;
        return mx;
    }
};

int main()
{
    vector<vector<int>> grid = {
        {1, 0},
        {0, 1}};

    Solution sol;
    int result = sol.largestIsland(grid);
    cout << result << endl;

    return 0;
}
