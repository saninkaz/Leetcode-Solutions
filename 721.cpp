#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent;

public:
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
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        unordered_map<string, int> mpp;
        DisjointSet ds(n);

        for (int i = 0; i < n; i++)
        {
            vector<string> it = accounts[i];
            for (int j = 1; j < it.size(); j++)
            {
                string s = it[j];
                if (mpp.find(s) == mpp.end())
                {
                    mpp[s] = i;
                }
                else
                {
                    int parent = mpp[s];
                    ds.UnionByRank(parent, i);
                }
            }
        }

        vector<vector<string>> result_1(n);

        for (auto it : mpp)
        {
            string mail = it.first;
            int node = ds.findUPar(it.second);

            result_1[node].push_back(mail);
        }

        vector<vector<string>> result;

        for (int i = 0; i < n; i++)
        {
            if (result_1[i].size())
            {
                sort(result_1[i].begin(), result_1[i].end());
                result_1[i].insert(result_1[i].begin(), accounts[i][0]);
                result.push_back(result_1[i]);
            }
        }

        return result;
    }
};

int main()
{
    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"}};

    Solution sol;
    vector<vector<string>> result = sol.accountsMerge(accounts);

    for (auto &acc : result)
    {
        for (auto &str : acc)
        {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}
