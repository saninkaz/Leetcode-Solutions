#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // private:
    //     bool rec(int index, int target, vector<int> &nums, vector<vector<int>> &dp)
    //     {
    //         if (target == 0)
    //             return true;
    //         if (index == 0)
    //         {
    //             return nums[0]==target;
    //         }

    //         if (dp[index][target] != -1)
    //             return dp[index][target];

    //         bool notTake = rec(index - 1, target, nums, dp);
    //         bool take = false;
    //         if (nums[index] <= target)
    //             take = rec(index - 1, target - nums[index], nums, dp);

    //         return dp[index][target] = take || notTake;
    //     }

public:
    bool canPartition(vector<int> &nums)
    {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (total % 2 != 0)
            return false;

        int target = total / 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }
        if (nums[0] <= target)
            dp[0][nums[0]] = true;
        for (int index = 1; index < n; index++)
        {
            for (int t = 1; t <= target; t++)
            {
                bool notTake = false;
                bool take = false;

                notTake = dp[index - 1][t];

                if (nums[index] <= t)
                    take = dp[index - 1][t - nums[index]];

                dp[index][t] = take || notTake;
            }
        }
        return dp[n - 1][target];
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 5, 11, 5};
    vector<int> nums2 = {1, 2, 3, 5};

    cout << boolalpha << sol.canPartition(nums1) << endl; // true
    cout << boolalpha << sol.canPartition(nums2) << endl; // false

    return 0;
}
