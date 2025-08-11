#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int n = nums.size();

        int xr = 0;
        for (int i = 0; i < n; i++)
        {
            xr ^= nums[i];
        }

        int right = (xr & xr - 1) ^ xr;
 
        int b1 = 0, b2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] & right)
            {
                b1 ^= nums[i];
            }
            else
            {
                b2 ^= nums[i];
            }
        }

        vector<int> result = {b1, b2};

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 1, 3, 2, 5}; // Example input
    vector<int> result = sol.singleNumber(nums);

    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
