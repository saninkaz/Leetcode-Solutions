#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> result;
        map<int, map<int, vector<int>>> mpp; // Use multiset instead of vector if duplicate values in tree are allowed

        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty())
        {
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                TreeNode *node = q.front().first;
                int level = q.front().second.first;
                int vertical = q.front().second.second;
                q.pop();

                mpp[vertical][level].push_back(node->val);

                if (node->left)
                    q.push({node->left, {level + 1, vertical - 1}});
                if (node->right)
                    q.push({node->right, {level + 1, vertical + 1}});
            }
        }

        for (auto it : mpp)
        {
            vector<int> temp;
            for (auto it2 : it.second)
            {
                sort(it2.second.begin(),it2.second.end());
                for (auto it3 : it2.second)
                {
                    temp.push_back(it3);
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};

// Sample Input Construction:
// Input: root = [1,2,3,4,5,6,7]

TreeNode *buildSampleTree()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

int main()
{
    TreeNode *root = buildSampleTree();
    Solution sol;
    vector<vector<int>> result = sol.verticalTraversal(root);

    for (const auto &col : result)
    {
        for (int val : col)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
