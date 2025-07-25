#include <iostream>
#include <vector>
#include <climits>
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
    int height(TreeNode *node, int &maxSum)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int lh = height(node->left, maxSum);
        int rh = height(node->right, maxSum);

        maxSum = max(maxSum, lh + rh + node->val);

        return node->val + max(lh, rh);
    }

public:
    int maxPathSum(TreeNode *root)
    {
        int sum = INT_MIN;

        int ht = height(root, sum);
        return sum;
    }
};

// Sample Input Construction
TreeNode *buildSampleTree()
{
    // Example: root = [-10,9,20,null,null,15,7]
    TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    return root;
}

int main()
{
    Solution sol;
    TreeNode *root = buildSampleTree();
    int result = sol.maxPathSum(root);
    cout << "Maximum Path Sum: " << result << endl;
    return 0;
}
