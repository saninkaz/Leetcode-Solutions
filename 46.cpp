#include <iostream>
#include <vector>
using namespace std;

// Solution 1 takes extra space complexity O(n)

// class Solution
// {
// private:
//     void rec(vector<int> &nums, int n, vector<int> &temp, vector<int> &mpp, vector<vector<int>> &result)
//     {
//         if (temp.size() == n)
//         {
//             result.push_back(temp);
//             return;
//         }
//         for (int i = 0; i < n; i++)
//         {
//             if (!mpp[i])
//             {
//                 temp.push_back(nums[i]);
//                 mpp[i] = 1;
//                 rec(nums, n, temp, mpp, result);
//                 temp.pop_back();
//                 mpp[i] = 0;
//             }
//         }
//     }

// public:
//     vector<vector<int>> permute(vector<int> &nums)
//     {
//         vector<vector<int>> result;
//         vector<int> temp = {};
//         int n = nums.size();
//         vector<int> mpp(n, 0);

//         rec(nums, n, temp, mpp, result);
//         return result;
//     }
// };

// Most optimal space complexity

class Solution
{
private:
    void rec(int index, vector<int> &nums, int n, vector<vector<int>> &result)
    {
        if(index == n){
            result.push_back(nums);
            return;
        }
        for (int i = index; i < n; i++)
        {
            swap(nums[i], nums[index]);
            rec(index + 1, nums, n, result);
            swap(nums[i], nums[index]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        int n = nums.size();
        rec(0, nums, n, result);
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3}; // You can modify this input
    vector<vector<int>> res = sol.permute(nums);

    // Print the result
    for (const auto &perm : res)
    {
        for (int num : perm)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
