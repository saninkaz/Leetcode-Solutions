#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    bool computeSubarrays(vector<int> &nums, int n, int maxSum, int k)
    {
        int sum = 0;
        int noOfSubarrays = 1;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (sum > maxSum)
            {
                noOfSubarrays++;
                sum = nums[i];
            }
            if (noOfSubarrays > k)
            {
                return false;
            }
        }
        return true;
    }

    int splitArray(vector<int> &nums, int k)
    {

        int n = nums.size();
        int mx = INT_MIN;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            mx = max(nums[i], mx);
            sum += nums[i];
        }

        int low = mx, high = sum;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (computeSubarrays(nums, n, mid, k))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;

    int result = sol.splitArray(nums, k);
    cout << "Minimized largest sum of split: " << result << endl;

    return 0;
}
