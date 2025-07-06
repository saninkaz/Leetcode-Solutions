#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Bit manipulation solution

// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> result;

//         int n = nums.size();

//         for(int i=0;i<(1<<n);i++){
//             vector<int> temp ={};
//             for(int j=0;j<n;j++){
//                 if(i &(1<<j)){
//                     temp.push_back(nums[j]);
//                 }
//             }
//             result.push_back(temp);
//         }

//         return result;
//     }
// };

// Recursive solution

class Solution
{
private:
    void rec(int i, vector<int> &nums, vector<int> &temp, vector<vector<int>> &result, int n)
    {
        if (i >= n)
        {
            result.push_back(temp);
            return;
        }
  
        temp.push_back(nums[i]);
        rec(i + 1, nums, temp, result, n);
        temp.pop_back();
        rec(i + 1, nums, temp, result, n);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> temp = {};
        int i = 0;

        int n = nums.size();

        rec(i, nums, temp, result, n);

        return result;
    }
};

int main()
{
    Solution sol;

    // Example input
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol.subsets(nums);

    // Print the result
    for (const auto &subset : result)
    {
        cout << "[";
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
