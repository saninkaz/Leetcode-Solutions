#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
    void preOrderreverse(TreeNode *node, int level, vector<int> &result)
    {
        if (node == nullptr)
        {
            return;
        }

        if (level == result.size())
        {
            result.push_back(node->val);
        }
        preOrderreverse(node->right, level + 1, result);
        preOrderreverse(node->left, level + 1, result);
    }

public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;
        preOrderreverse(root, 0, result);
        return result;
    }
};

// Utility function to build a tree from a vector (level order)
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

        // Left child
        if (i < nodes.size() && nodes[i] != INT_MIN)
        {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;

        // Right child
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
    vector<int> input = {1, 2, 3, INT_MIN, 5, INT_MIN, 4};

    TreeNode *root = buildTree(input);
    Solution sol;
    vector<int> result = sol.rightSideView(root);

    cout << "Output: [";
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i];
        if (i != result.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
