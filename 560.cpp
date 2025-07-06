#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

// class Solution
// {
// public:
//     int subarraySum(vector<int> &nums, int k)
//     {

//         int n = nums.size();
//         unordered_map<int, int> hash;
//         int sum = 0;
//         int count = 0;

//         for (int i = 0; i < n; i++)
//         {
//             sum += nums[i];
//             if (sum == k)
//             {
//                 count++;
//             }
//             if (hash.find(sum - k) != hash.end())
//             {
//                 count+=hash[sum-k];
//             }
//             hash[sum]++;
//         }

//         return count;
//     }
// };

// OR (same solution written in short)

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {

        int n = nums.size();
        unordered_map<int, int> hash;
        hash[0]=1;
        int sum = 0;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            count+=hash[sum-k];
            hash[sum]++;
        }

        return count;
    }
};



int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    int k = 3;

    int result = sol.subarraySum(nums, k);
    cout << "Total subarrays with sum " << k << ": " << result << endl;

    return 0;
}
