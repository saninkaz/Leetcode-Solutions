
class DisjointSet {
public:
    vector<int> parent, size;
    vector<set<int>> componentSet;

    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        componentSet.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
            componentSet[i].insert(i); 
        }
    }

    int findUPar(int u) {
        if (parent[u] == u)
            return u;
        return parent[u] = findUPar(parent[u]);
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
            componentSet[pv].insert(componentSet[pu].begin(), componentSet[pu].end());
            componentSet[pu].clear();
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
            componentSet[pu].insert(componentSet[pv].begin(), componentSet[pv].end());
            componentSet[pv].clear();
        }
    }

    void disable(int node) {
        int root = findUPar(node);
        componentSet[root].erase(node);
    }

    int getSmallestOnline(int node) {
        int root = findUPar(node);
        if (componentSet[root].empty()) return -1;
        return *componentSet[root].begin();
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DisjointSet ds(c);
        vector<bool> isOnline(c + 1, true);

        for (auto& conn : connections) {
            ds.unionBySize(conn[0], conn[1]);
        }

        vector<int> result;
        for (auto& q : queries) {
            int type = q[0], node = q[1];
            if (type == 1) {
                if (isOnline[node]) {
                    result.push_back(node);
                } else {
                    int res = ds.getSmallestOnline(node);
                    result.push_back(res);
                }
            } else {
                if (isOnline[node]) {
                    isOnline[node] = false;
                    ds.disable(node);
                }
            }
        }

        return result;
    }
};
