#include <iostream>
#include <vector>
#include <queue>
#include <deque>
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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == nullptr)
            return result;

        queue<TreeNode *> q;
        q.push(root);
        int flag = 0;

        while (!q.empty())
        {
            int len = q.size();
            vector<int> temp(len);
            for (int i = 0; i < len; i++)
            {
                TreeNode *node = q.front();
                if (flag == 1)
                {
                    temp[len - 1 - i] = node->val;
                }
                else
                {
                    temp[i] = node->val;
                }
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            flag = !flag;
            result.push_back(temp);
        }
        return result;
    }
};

// Helper function to build binary tree from vector (using INT_MIN as null)
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
    vector<int> nodes = {3, 9, 20, INT_MIN, INT_MIN, 15, 7}; // Example input

    TreeNode *root = buildTree(nodes);

    Solution sol;
    vector<vector<int>> result = sol.zigzagLevelOrder(root);

    for (const auto &level : result)
    {
        for (int val : level)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
