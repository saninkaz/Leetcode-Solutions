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