#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int numSub(vector<int> &nums, int k)
    {
        int n = nums.size();
        int j = 0;
        int num = 0;
        int total = 0;

        for (int i = 0; i < n; i++)
        {
            num += nums[i] % 2 != 0 ? 1 : 0;

            while (num > k)
            {
                num -= nums[j] % 2 != 0 ? 1 : 0;
                j++;
            }
            total += i - j + 1;
        }
        return total;
    }

public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return numSub(nums, k) - numSub(nums, k - 1);
    }
};

int main()
{
    Solution sol;

    // Sample input
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;

    // Call the function and print the result
    int result = sol.numberOfSubarrays(nums, k);
    cout << "Number of nice subarrays with " << k << " odd numbers: " << result << endl;

    return 0;
}
