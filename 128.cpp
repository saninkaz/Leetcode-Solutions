#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>

using namespace std;

// Solution 1 (Brute force)

// class Solution
// {
// public:
//     int longestConsecutive(vector<int> &nums)
//     {

//         int n = nums.size();
//         int count = 0;
//         unordered_map<int, int> hash;
//         int mx=0;

//         for (int i = 0; i < n; i++)
//         {
//             hash[nums[i]] = i;
//         }

//         for (int i = 0; i < n; i++)
//         {
//             count = 1;
//             while(hash.find(nums[i] + count) != hash.end())
//             {
//                 count++;
//             }
//             mx=max(count,mx);
//         }

//         return mx;
//     }
// };

// Solution 2

// class Solution
// {
// public:
//     int longestConsecutive(vector<int> &nums)
//     {

//         int n = nums.size();
//         int count = 1;
//         int mx = 0;
//         sort(nums.begin(), nums.end());

//         for (int i = 1; i < n; i++)
//         {
//             if (nums[i] == nums[i - 1])
//             {
//                 continue;
//             }
//             else if (nums[i] == nums[i - 1] + 1)
//             {
//                 count++;
//             }
//             else
//             {
//                 mx = max(count, mx);
//                 count = 1;
//             }
//         }
//         mx = max(count, mx);
//         if (n)
//             return mx;
//         else
//         {
//             return 0;
//         }
//     }
// };

// Solution 3 (optimal under non worst case conditions for set (did not work in leetcode))

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {

        int n = nums.size();
        int count = 0;
        unordered_set<int> hash;
        int mx=0;

        for (int i = 0; i < n; i++)
        {
            hash.insert(nums[i]);
        }

        for (int i = 0; i < n; i++)
        {
            count = 1;
            if(hash.find(nums[i]-count) == hash.end()){
            while(hash.find(nums[i] + count) != hash.end())
            {
                count++;
            }
        }
            mx=max(count,mx);
        }

        return mx;
    }
};

int main()
{
    Solution sol;

    // Example input
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};

    // Function call
    int result = sol.longestConsecutive(nums);

    // Output result
    cout << "Longest consecutive sequence length: " << result << endl;

    return 0;
}
