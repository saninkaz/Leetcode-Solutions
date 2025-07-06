#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {

        int n = nums.size();

        if (n == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        if (nums[n - 1] > nums[n - 2])
            return n - 1;

        int low = 1, high = n - 2;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            else if (nums[mid + 1] > nums[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return -1;
    }
};

int main()
{
    Solution sol;

    // Example test case 1
    vector<int> nums1 = {1, 2, 1, 3, 5, 6, 4};
    int peakIndex1 = sol.findPeakElement(nums1);
    cout << "Peak index in nums1: " << peakIndex1 << endl;

    return 0;
}
