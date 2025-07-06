#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {

        int n = nums.size();
        int low = 0, high = n - 1;
        int mn = INT_MAX;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] < nums[high])
            {
                mn = min(nums[mid], mn);
                high = mid - 1;
            }
            else
            {
                mn = min(nums[low], mn);
                low = mid + 1;
            }
        }

        return mn;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {5, 1, 2, 3, 4};

    int result = sol.findMin(nums);

    cout << "Minimum element: " << result << endl;

    return 0;
}
