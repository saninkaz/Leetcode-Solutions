#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
using namespace std;

class Solution
{
public:
    int computeSum(vector<int> &nums, int n, int divisor)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += ceil((double)nums[i] / (double)divisor);
        }

        return sum;
    }

    int smallestDivisor(vector<int> &nums, int threshold)
    {

        int n = nums.size();
        if(n > threshold) return -1;
        int mx = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            mx = max(nums[i], mx);
        }

        int low = 1, high = mx;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            int sum = computeSum(nums, n, mid);
            if (sum > threshold)
            {
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return low;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1,2,5,9};
    int threshold = 6;

    int result = sol.smallestDivisor(nums, threshold);
    cout << "Smallest divisor: " << result << endl;

    return 0;
}
