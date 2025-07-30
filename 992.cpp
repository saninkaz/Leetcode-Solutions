#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int subArr(vector<int> &nums, int k)
    {
        int n = nums.size();
        int res = 0;
        int j = 0;
        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++)
        {
            mpp[nums[i]]++;

            while (mpp.size() > k)
            {
                mpp[nums[j]]--;

                if (mpp[nums[j]] == 0)
                {
                    mpp.erase(nums[j]);
                }
                j++;
            }

            if (mpp.size() <= k)
            {
                res += (i - j + 1);
            }
        }

        return res;
    }

public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return subArr(nums, k) - subArr(nums, k - 1);
    }
};

int main()
{
    Solution sol;

    // Sample input
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;

    // Call the function and print the result
    int result = sol.subarraysWithKDistinct(nums, k);
    cout << "Number of good subarrays with exactly " << k << " distinct integers: " << result << endl;

    return 0;
}
