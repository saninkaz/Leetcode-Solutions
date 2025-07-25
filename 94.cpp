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
    void inOrder(TreeNode *node, vector<int> &I)
    {
        if (node == nullptr)
            return;

        inOrder(node->left, I);
        I.push_back(node->val);
        inOrder(node->right, I);
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> I;
        inOrder(root, I);
        return I;
    }
};

// Manually build the sample tree: [1,null,2,3]
TreeNode *buildSampleTree()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    return root;
}

int main()
{
    // Sample Input: root = [1,null,2,3]
    TreeNode *root = buildSampleTree();

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);

    // Output the result
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
