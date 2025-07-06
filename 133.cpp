#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> neighbors;

    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
private:
    void dfs(Node *node, Node **res, unordered_map<Node *, Node *> &visited)
    {

        visited[node] = (*res);

        for (auto it : node->neighbors)
        {

            if (!visited.count(it))
            {
                Node *tempit = new Node(it->val);
                (*res)->neighbors.push_back(tempit);
                dfs(it, &tempit, visited);
            }
            else
            {
                (*res)->neighbors.push_back(visited[it]);
            }
        }
    }

public:
    Node *cloneGraph(Node *node)
    {
        unordered_map<Node *, Node *> visited;
        int start = 1;
        if (node)
        {
            start = node->val;
        }
        if (node)
        {
            Node *res = new Node(node->val);
            dfs(node, &res, visited);
            return visited[node];
        }
        else
        {
            return nullptr;
        }
    }
};

// Utility function to print graph (for testing)
void printGraph(Node *node, unordered_set<int> &visited)
{
    if (!node || visited.count(node->val))
        return;

    visited.insert(node->val);
    cout << "Node " << node->val << ": ";
    for (auto neighbor : node->neighbors)
    {
        cout << neighbor->val << " ";
    }
    cout << endl;

    for (auto neighbor : node->neighbors)
    {
        printGraph(neighbor, visited);
    }
}

int main()
{
    // Example: adjList = [[2,4],[1,3],[2,4],[1,3]]
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);

    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    Solution sol;
    Node *cloned = sol.cloneGraph(node1);

    cout << "Original Graph:\n";
    unordered_set<int> visited;
    printGraph(node1, visited);

    cout << "\nCloned Graph:\n";
    visited.clear();
    printGraph(cloned, visited);

    return 0;
}
