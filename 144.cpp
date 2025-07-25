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

// Preorder traversal function to implement
class Solution
{
private:
    void preOrder(TreeNode *node, vector<int> &P)
    {
        if (node == nullptr)
            return;

        P.push_back(node->val);
        preOrder(node->left, P);
        preOrder(node->right, P);
    }

public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> P;
        preOrder(root, P);
        return P;
    }
};

// Helper function to build the specific tree: [1,null,2,3]
TreeNode *buildSampleTree()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    return root;
}

int main()
{
    // Build the tree from sample input: [1,null,2,3]
    TreeNode *root = buildSampleTree();

    Solution sol;
    vector<int> result = sol.preorderTraversal(root);

    // Print result
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
