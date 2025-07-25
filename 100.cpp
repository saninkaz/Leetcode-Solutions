#include <iostream>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
private:
    bool check(TreeNode *p, TreeNode *q)
    {
        // if (p == nullptr && q == nullptr)
        // {
        //     return true;
        // }
        // if (p == nullptr && q != nullptr || q == nullptr && p != nullptr)
        // {
        //     return false;
        // }

        // Can be written as

         if (p == nullptr || q == nullptr)
        {
            return p==q;
        }
    
        if (p->val != q->val)
        {
            return false;
        }
        if (check(p->left, q->left) == false)
        {
            return false;
        };

        if (check(p->right, q->right) == false)
        {
            return false;
        };

        return true;
    }

public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {

        return check(p, q);
    }
};

// Helper function to construct binary tree from vector
TreeNode *buildTree(const vector<int> &nodes)
{
    if (nodes.empty() || nodes[0] == INT_MIN)
        return nullptr;

    TreeNode *root = new TreeNode(nodes[0]);
    queue<TreeNode *> q;
    q.push(root);
    int i = 1;

    while (i < nodes.size())
    {
        TreeNode *current = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != INT_MIN)
        {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != INT_MIN)
        {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

int main()
{
    vector<int> vec1 = {1, 2, 3}; // use INT_MIN for null nodes
    vector<int> vec2 = {1, 2, 3};

    TreeNode *p = buildTree(vec1);
    TreeNode *q = buildTree(vec2);

    Solution sol;
    bool result = sol.isSameTree(p, q);

    cout << (result ? "true" : "false") << endl;

    return 0;
}
