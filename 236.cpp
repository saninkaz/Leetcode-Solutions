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
public:
    // Function to find LCA of nodes p and q in the binary tree
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || root == p || root == q)
        {
            return root;
        }

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left == nullptr)
        {
            return right;
        }

        if (right == nullptr)
        {
            return left;
        }

        return root;
    }
};

// Utility to build a binary tree from level-order vector using INT_MIN as null
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
        TreeNode *curr = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != INT_MIN)
        {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != INT_MIN)
        {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

// Helper to find node with specific value
TreeNode *findNode(TreeNode *root, int val)
{
    if (!root)
        return nullptr;
    if (root->val == val)
        return root;
    TreeNode *left = findNode(root->left, val);
    if (left)
        return left;
    return findNode(root->right, val);
}

int main()
{
    vector<int> nodes = {3, 5, 1, 6, 2, 0, 8, INT_MIN, INT_MIN, 7, 4};
    TreeNode *root = buildTree(nodes);

    TreeNode *p = findNode(root, 5); // set value of p
    TreeNode *q = findNode(root, 1); // set value of q

    Solution sol;
    TreeNode *lca = sol.lowestCommonAncestor(root, p, q);
    if (lca)
        cout << "LCA: " << lca->val << endl;
    else
        cout << "LCA not found." << endl;

    return 0;
}
