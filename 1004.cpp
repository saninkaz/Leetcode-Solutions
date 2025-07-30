#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {

        int n = nums.size();
        int count = 0;
        int j = 0;
        int maxCount = 0;
        int numZeroes = 0;
        vector<int> mpp(2, -1);

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                numZeroes++;
            }
            if (numZeroes <= k)
            {
                maxCount = max(maxCount, i - j + 1);
            }
            while (numZeroes > k)
            {
                if (nums[j] == 0)
                {
                    numZeroes--;
                }
                j++;
            }
        }
        return maxCount;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    int result = sol.longestOnes(nums, k);
    cout << "Maximum number of consecutive 1's: " << result << endl;
    return 0;
}
