#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {

        int n = nums.size();
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                return true;
            }
            else if (nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                low = low + 1;
                high = high - 1;
                continue;
            }
            else if (nums[high] >= nums[mid])
            {
                if (nums[mid] <= target && nums[high] >= target)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            else
            {
                if (nums[mid] >= target && nums[low] <= target)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;

    bool found = sol.search(nums, target);
    cout << (found ? "true" : "false") << endl;

    return 0;
}
