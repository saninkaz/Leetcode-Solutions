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
    void postOrder(TreeNode *node, vector<int> &P)
    {
        if (node == nullptr)
            return;

        postOrder(node->left, P);
        postOrder(node->right, P);
        P.push_back(node->val);
    }

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> P;
        postOrder(root, P);
        return P;
    }
};

// Sample tree: [1,null,2,3]
//     1
//      \
//       2
//      /
//     3
TreeNode *buildSampleTree()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    return root;
}

int main()
{
    TreeNode *root = buildSampleTree();

    Solution sol;
    vector<int> result = sol.postorderTraversal(root);

    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
