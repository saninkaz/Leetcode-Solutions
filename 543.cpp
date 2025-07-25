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
    int height(TreeNode *node, int &maxDiameter)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int lh = height(node->left,maxDiameter);
        int rh = height(node->right,maxDiameter);

        maxDiameter = max(maxDiameter, lh + rh);

        return 1 + max(lh, rh);
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;

        int ht = height(root,diameter);
        return diameter;
    }
};

// Sample tree: [1,2,3,4,5]
//        1
//       / \
//      2   3
//     / \     
//    4   5
TreeNode *buildSampleTree()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

int main()
{
    TreeNode *root = buildSampleTree();

    Solution sol;
    int diameter = sol.diameterOfBinaryTree(root);

    cout << "Diameter of the tree: " << diameter << endl;

    return 0;
}
