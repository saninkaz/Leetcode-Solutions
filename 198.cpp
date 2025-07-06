#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
private:
    int rec(int index, vector<int> &nums, vector<int> &dp)
    {
        if (index >= nums.size())
        {
            return 0;
        }
        if (dp[index] != -1)
        {
            return dp[index];
        }

        int l = rec(index + 1, nums, dp);
        int r = rec(index + 2, nums, dp) + nums[index];

        return dp[index] = max(l, r);
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        vector<int> dp(n + 1, -1);

        sum = rec(0, nums, dp);
        return sum;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 1};
    vector<int> nums2 = {2, 7, 9, 3, 1};

    cout << "Max loot for nums1: " << sol.rob(nums1) << endl;
    cout << "Max loot for nums2: " << sol.rob(nums2) << endl;

    return 0;
}
