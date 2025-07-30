#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int mx = nums[0];

        for (int i = 1; i < n; i++)
        {
            if (i > mx)
                return false;
            mx = max(mx, nums[i] + i);
        }

        if (mx >= n - 1)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution sol;

    // Example usage
    vector<int> nums = {2, 3, 1, 1, 4};

    bool result = sol.canJump(nums);
    cout << (result ? "true" : "false") << endl;

    return 0;
}
