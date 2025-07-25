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
    bool rec(TreeNode *l, TreeNode *r)
    {
        if (l == nullptr || r == nullptr)
        {
            return l == r;
        }

        if (l->val != r->val)
        {
            return false;
        }

        return rec(l->left, r->right) &&
               rec(l->right, r->left);
    }

public:
    // Recursive version
    bool isSymmetricRecursive(TreeNode *root)
    {

        return rec(root->left, root->right);
    }
};

// Utility to build tree from level-order vector using INT_MIN as null
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
    vector<int> nodes = {1, 2, 2, 3, 4, 4, 3}; // Change this input for testing

    TreeNode *root = buildTree(nodes);
    Solution sol;

    cout << boolalpha;
    cout << "Recursive: " << sol.isSymmetricRecursive(root) << endl;

    return 0;
}
