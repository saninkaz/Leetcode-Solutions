#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();

        int ans = 0;

        for (int i = 0; i < 32; i++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {

                if (nums[j] & (1 << i))
                {
                    sum++;
                }
            }

            if (sum % 3 != 0)
            {
                ans = ans | (1 << i);
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 2, 3, 2}; // Example input
    cout << sol.singleNumber(nums) << endl;
    return 0;
}
