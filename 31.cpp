#include <iostream>
#include <vector>
#include <algorithm> // For reverse and swap
#include <bits/stdc++.h>

using namespace std;

// Solution 1 (inbuilt function)

// class Solution
// {
// public:
//     void nextPermutation(vector<int> &nums)
//     {
//         next_permutation(nums.begin(),nums.end());
//     }
// };

// Solution 2 (implementing the inbuilt function)

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int dip = 0;
        int flag = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                dip = i;
                flag = 1;
                break;
            }
        }
        for (int i = n - 1; i >= dip + 1; i--)
        {
            if (nums[i] > nums[dip])
            {
                swap(nums[i], nums[dip]);
                break;
            }
        }
        if (flag == 0)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            reverse(nums.begin() + dip + 1, nums.end());
        }
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {1, 3, 2};

    sol.nextPermutation(nums);

    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
