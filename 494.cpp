#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int rec(int index, vector<int> &nums, int target, vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            if (target == 0 && nums[0] == 0)
                return 2;
            if (target == 0 || target == nums[0])
                return 1;
            return 0;
        }

        if (dp[index][target] != -1)
        {
            return dp[index][target];
        }

        int notTake = rec(index - 1, nums, target, dp);
        int take = 0;
        if (nums[index] <= target)
        {
            take = rec(index - 1, nums, target - nums[index], dp);
        }

        return dp[index][target] = take + notTake;
    }

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {

        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        target = (totalSum + target);
        if (target < 0 || (target) % 2)
            return 0;
        vector<vector<int>> dp(n, vector<int>(((target) / 2) + 1, -1));
        int res = rec(n - 1, nums, target/2, dp);
        return res;
    }
};

int main()
{
    // Sample Input:
    // nums = [1, 1, 1, 1, 1], target = 3
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    Solution sol;
    int result = sol.findTargetSumWays(nums, target);

    cout << "Number of ways to reach target " << target << " is: " << result << endl;

    return 0;
}