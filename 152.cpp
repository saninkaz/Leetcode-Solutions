#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Brute force solution

// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int n=nums.size();

//         int mx=0;

//         for(int i=0;i<n;i++){
//             int product=1;
//             for(int j=i;j<n;j++){
//                 product*=nums[j];
//                 mx=max(product,mx);
//             }
//         }
//         return mx;
//     }
// };

// Solution 2

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();

        int mx = INT_MIN;

        int pref = 1;
        int suff = 1;

        for (int i = 0; i < n; i++)
        {
            if (pref == 0)
            {
                pref = 1;
            }
            if (suff == 0)
            {
                suff = 1;
            }
            pref *= nums[i];
            suff *= nums[n - 1 - i];
            mx = max(max(pref, suff), mx);
        }
        return mx;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {2, 3, -2, 4}; // Example input
    int result = sol.maxProduct(nums);

    cout << "Maximum product subarray: " << result << endl;

    return 0;
}
