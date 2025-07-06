#include <iostream>
#include <vector>
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
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        vector<int> nums1(nums.begin(), nums.end() - 1);

        sum = max(rec(0, nums1, dp1), rec(1, nums, dp2));
        return sum;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {2, 3, 2};
    vector<int> nums2 = {1, 2, 3, 1};
    vector<int> nums3 = {1, 2, 3};

    cout << "Max loot for nums1: " << sol.rob(nums1) << endl;
    cout << "Max loot for nums2: " << sol.rob(nums2) << endl;
    cout << "Max loot for nums3: " << sol.rob(nums3) << endl;

    return 0;
}
