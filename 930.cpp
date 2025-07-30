#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Prefix Sum Solution

// class Solution
// {
// public:
//     int numSubarraysWithSum(vector<int> &nums, int goal)
//     {
//         int n = nums.size();
//         int sum = 0;
//         int res = 0;

//         unordered_map<int, int> mpp;
//         mpp[0] = 1;

//         for (int i = 0; i < n; i++)
//         {
//             sum += nums[i];
//             res += mpp[sum - goal];
//             mpp[sum]++;
//         }

//         return res;
//     }
// };

// Optimal Solution

class Solution
{

private:
    int numSub(vector<int> &nums, int goal)
    {
        1
        int n = nums.size();
        int sum = 0;
        int res = 0;
        int j = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            while (sum > goal)
            {
                sum -= nums[j];
                j++;
            }
            res += (i - j + 1);
        }
        return res;
    }

public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return numSub(nums, goal) - numSub(nums, goal - 1);
    }
};

int main()
{
    Solution sol;

    // Sample input
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;

    // Call the function and print the result
    int result = sol.numSubarraysWithSum(nums, goal);
    cout << "Number of subarrays with sum " << goal << ": " << result << endl;

    return 0;
}
