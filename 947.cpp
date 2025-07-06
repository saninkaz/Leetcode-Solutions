#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> parent, size;

    DisjointSet(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void UnionBySize(int u, int v)
    {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv)
            return;

        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

// Solution 1 (memory limit exceeded in leetcode)

// class Solution
// {
// private:
//     void bfs(int i, int j, vector<vector<int>> &graph, vector<vector<int>> &visited, int mx, DisjointSet &ds,queue<pair<int, int>> &q)
//     {
//         int node = (i * mx) + j;
//         q.push({i, j});
//         visited[i][j] = 1;

//         while (!q.empty())
//         {
//             int row = q.front().first;
//             int col = q.front().second;
//             q.pop();

//             // Traverse in row and col

//             for (int z = 0; z < mx; z++)
//             {
//                 if (graph[row][z] == 1 && !visited[row][z])
//                 {
//                     visited[row][z] = 1;
//                     q.push({row, z});
//                     ds.UnionBySize((row * mx) + z, (row * mx) + col);
//                 }
//                 if (graph[z][col] == 1 && !visited[z][col])
//                 {
//                     visited[z][col] = 1;
//                     q.push({z, col});
//                     ds.UnionBySize((z * mx) + col, (row * mx) + col);
//                 }
//             }
//         }
//     }

// public:
//     int removeStones(vector<vector<int>> &stones)
//     {

//         int n = stones.size();
//         int mx = INT_MIN;
//         for (auto it : stones)
//         {
//             int row = it[0];
//             int col = it[1];

//             mx=max(row,mx);
//             mx=max(col,mx);
//         }
//         mx += 1;
//         DisjointSet ds(mx * mx);

//         int delrow[4] = {-1, 0, 1, 0};
//         int delcol[4] = {0, 1, 0, -1};

//         vector<vector<int>> graph(mx, vector<int>(mx, 0));

//         for (auto it : stones)
//         {
//             int row = it[0];
//             int col = it[1];

//             if (graph[row][col])
//                 continue;

//             graph[row][col] = 1;
//         }

//         vector<vector<int>> visited(mx, vector<int>(mx, 0));
//         queue<pair<int, int>> q;

//         for (int i = 0; i < mx; i++)
//         {
//             for (int j = 0; j < mx; j++)
//             {
//                 if (graph[i][j] == 1 && !visited[i][j])
//                 {
//                     bfs(i, j, graph, visited, mx, ds,q);
//                 }
//             }
//         }

//         int count = 0;

//         for (int i = 0; i < (mx * mx); i++)
//         {
//             if (ds.findUPar(i) == i)
//             {
//                 count += (ds.size[i] - 1);
//             }
//         }

//         return count;
//     }
// };

class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {

        int n = stones.size();
        int mxr = INT_MIN;
        int mxc = INT_MIN;
        for (auto it : stones)
        {
            int row = it[0];
            int col = it[1];

            mxr = max(row, mxr);
            mxc = max(col, mxc);
        }
        DisjointSet ds(mxr+mxc+2);
        unordered_map<int,int> mpp;
        for(auto it: stones){
            int nodeRow= it[0];
            int nodeCol =it[1]+mxr+1;

            mpp[nodeRow]=1;
            mpp[nodeCol]=1;
            ds.UnionBySize(nodeRow,nodeCol);
        }

        int count =0;

        for(auto it: mpp){
            if(ds.findUPar(it.first)== it.first){
                count++;
            }
        }


        return stones.size()-count;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> stones = {
        {0, 1}, {1, 0}, {1, 1}};

    cout << sol.removeStones(stones) << endl;

    return 0;
}
