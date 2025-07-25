#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
    int rec(TreeNode *node)
    {
        if (node == nullptr)
            return 0;

        int l = 1 + rec(node->left);
        int r = 1 + rec(node->right);

        return max(l, r);
    }

public:
    int maxDepth(TreeNode *root)
    {
        int depth = 0;

        depth = rec(root);
        return depth;
    }
};

// Sample tree: [3,9,20,null,null,15,7]
//       3
//      / \
//     9  20
//        / \
//       15  7
TreeNode *buildSampleTree()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    return root;
}

int main()
{
    TreeNode *root = buildSampleTree();

    Solution sol;
    int depth = sol.maxDepth(root);

    cout << "Maximum Depth: " << depth << endl;

    return 0;
}
