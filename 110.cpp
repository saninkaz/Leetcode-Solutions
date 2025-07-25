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

// Brute solution

// class Solution
// {
// private:
//     int height(TreeNode *node)
//     {
//         if (node == nullptr)
//             return 0;

//         int l = 1 + height(node->left);
//         int r = 1 + height(node->right);

//         return max(l, r);
//     }

//     bool check(TreeNode *node)
//     {
//         if (node == nullptr)
//         {
//             return true;
//         }
//         if (abs(height(node->left) - height(node->right)) > 1)
//         {
//             return false;
//         };

//         if (check(node->left) == false)
//         {
//             return false;
//         };
//         if (check(node->right) == false)
//         {
//             return false;
//         };

//         return true;
//     }

// public:
//     bool isBalanced(TreeNode *root)
//     {
//         return check(root);
//     }
// };

// Optimal

class Solution
{
private:
    int height(TreeNode *node)
    {
        if (node == nullptr)
            return 0;

        int l = height(node->left);
        int r = height(node->right);
        if (l == -1 || r == -1)
            return -1;
        if (abs(l - r) > 1)
            return -1;

        return 1 + max(l, r);
    }

public:
    bool isBalanced(TreeNode *root)
    {
        return height(root) == -1 ? false : true;
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
    bool balanced = sol.isBalanced(root);

    cout << "Is Tree Balanced? " << (balanced ? "true" : "false") << endl;

    return 0;
}
