#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDifference(vector<int> &nums)
    {
        int n = nums.size();
        int target = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<bool>> dp(n, vector<bool>(target + 1, 0));

        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }
        if(nums[0] >= 0 && nums[0]<=target)
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
        int mn = INT_MAX;
        for (int i = 0; i <= target/2;i++)
        {
            if (dp[n - 1][i])
            {
                int s1 = i;
                int s2 = target - i;
                mn = min(abs(s1- s2),mn);
            }
        }
        return mn;
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {3, 9, 7, 3};
    vector<int> nums2 = {-36, 36};
    vector<int> nums3 = {2, -1, 0, 4, -2, -9};

    cout << "Minimum Difference for nums1: " << sol.minimumDifference(nums1) << endl;
    cout << "Minimum Difference for nums2: " << sol.minimumDifference(nums2) << endl;
    cout << "Minimum Difference for nums3: " << sol.minimumDifference(nums3) << endl;

    return 0;
}
